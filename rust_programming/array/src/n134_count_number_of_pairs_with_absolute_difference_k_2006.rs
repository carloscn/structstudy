
pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32
{
    if nums.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;

    for i in 0..nums.len() {
        for j in i..nums.len() {
            if i32::abs(nums[i] - nums[j]) == k as i32 {
                ret += 1;
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = count_k_difference(vec![1,2,2,1], 1);
        assert_eq!(ret, 4);
        let ret = count_k_difference(vec![1,3], 3);
        assert_eq!(ret, 0);
        let ret = count_k_difference(vec![3,2,1,5,4], 2);
        assert_eq!(ret, 3);
    }
}