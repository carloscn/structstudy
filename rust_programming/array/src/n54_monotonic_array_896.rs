
fn is_monotonic(nums: Vec<i32>) -> bool
{
    if nums.len() < 2 {
        return false;
    }

    let mut ret:bool;
    let mut last_ret:bool = (nums[1] - nums[0]) >= 0;

    for i in 1..(nums.len() - 1) {
        ret = nums[i + 1] - nums[i] >= 0;
        if last_ret != ret {
            return false;
        }
        last_ret = ret;
    }

    return true;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_empty() {
        let nums: Vec<i32> = vec![];
        assert_eq!(is_monotonic(nums), false);
    }

    #[test]
    fn test_single() {
        let nums = vec![1];
        assert_eq!(is_monotonic(nums), false);
    }

    #[test]
    fn test_increasing() {
        let nums = vec![1, 2, 3, 4, 5];
        assert_eq!(is_monotonic(nums), true);
    }

    #[test]
    fn test_decreasing() {
        let nums = vec![5, 4, 3, 2, 1];
        assert_eq!(is_monotonic(nums), true);
    }

    #[test]
    fn test_not_monotonic() {
        let nums = vec![1, 2, 3, 2, 5];
        assert_eq!(is_monotonic(nums), false);
    }

    #[test]
    fn test_duplicate_numbers() {
        let nums = vec![1, 2, 3, 3, 4];
        assert_eq!(is_monotonic(nums), true);
    }

}