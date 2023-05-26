
pub fn max_product(nums: Vec<i32>) -> i32
{
    if nums.is_empty() {
        return 0;
    }

    let mut max_val:i32 = i32::MIN;
    let mut sec_val:i32 = i32::MIN;

    for i in 0..nums.len() {
        if nums[i] >= max_val {
            sec_val = max_val;
            max_val = nums[i];
        } else if nums[i] < max_val &&
                  nums[i] > sec_val {
            sec_val = nums[i];
        }
    }

    return (sec_val - 1) * (max_val - 1);
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = max_product(vec![3,4,5,2]);
        assert_eq!(ret, 12);
        let mut ret = max_product(vec![1,5,4,5]);
        assert_eq!(ret, 16);
        let mut ret = max_product(vec![3,7]);
        assert_eq!(ret, 12);
        let mut ret = max_product(vec![7,3,1]);
        assert_eq!(ret, 12);
    }
}