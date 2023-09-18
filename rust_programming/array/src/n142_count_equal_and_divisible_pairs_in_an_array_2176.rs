
pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32
{
    let mut ret:i32 = 0;

    if nums.len() < 1 {
        return ret;
    }

    for i in 0..nums.len() {
        for j in (i + 1)..nums.len() {
            if nums[i] == nums[j] &&
               ((i * j) % k as usize == 0) {
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
        let ret = count_pairs(vec![3,1,2,2,2,1,3], 2);
        assert_eq!(ret, 4);

        let ret = count_pairs(vec![1,2,3,4], 1);
        assert_eq!(ret, 0);
    }
}