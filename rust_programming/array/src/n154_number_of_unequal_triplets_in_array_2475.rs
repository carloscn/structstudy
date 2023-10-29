
pub fn unequal_triplets(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if nums.len() < 1 {
        return ret;
    }

    for i in 0..nums.len() - 2 {
        for j in i + 1..nums.len() - 1 {
            for k in j + 1..nums.len() {
                if nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k] {
                    ret += 1;
                }
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
        let ret = unequal_triplets(vec![4,4,2,4,3]);
        assert_eq!(ret, 3);

        let ret = unequal_triplets(vec![1,1,1,1,1]);
        assert_eq!(ret, 0);
    }
}