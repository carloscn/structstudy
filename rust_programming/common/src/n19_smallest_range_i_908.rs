
pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32
{
    if 0 == nums.len() {
        return 0;
    }

    let nums_min = nums.iter().min().unwrap().clone() + k.abs();
    let nums_max = nums.iter().max().unwrap().clone() - k.abs();
    let delta_min = nums_max - nums_min;

    if delta_min < 0 {
        return 0;
    }

    delta_min
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_empty() {
        let nums = vec![];
        assert_eq!(smallest_range_i(nums, 5), 0);
    }

    #[test]
    fn test_single_element() {
        let nums = vec![10];
        assert_eq!(smallest_range_i(nums, 5), 0);
    }

    #[test]
    fn test_range_smaller_than_k() {
        let nums = vec![10, 12];
        assert_eq!(smallest_range_i(nums, 5), 0);
    }

    #[test]
    fn test_range_greater_than_k() {
        let nums = vec![10, 20, 30, 40];
        assert_eq!(smallest_range_i(nums, 5), 20);
    }

    #[test]
    fn test_range_equal_to_k() {
        let nums = vec![10, 15, 20];
        assert_eq!(smallest_range_i(nums, 5), 0);
    }

    #[test]
    fn test_negative_numbers() {
        let nums = vec![-10, -5, 0, 5, 10];
        assert_eq!(smallest_range_i(nums, 5), 10);
    }

    #[test]
    fn test_negative_k() {
        let nums = vec![10, 20, 30, 40];
        assert_eq!(smallest_range_i(nums, -5), 20);
    }
}