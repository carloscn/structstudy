
pub fn max_ascending_sum(nums: Vec<i32>) -> i32
{
    if nums.len() < 1 {
        return 0;
    }

    let mut max_sum:i32 = i32::MIN;
    let mut sum:i32 = 0;

    for i in 0..nums.len() {
        if (i < nums.len() - 1) && (nums[i + 1] - nums[i] > 0) {
            sum += nums[i];
        } else {
            sum += nums[i];
            max_sum = max_sum.max(sum);
            sum = 0;
        }
    }

    return max_sum;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = max_ascending_sum(vec![10,20,30,5,10,50]);
        assert_eq!(ret, 65);
        let ret = max_ascending_sum(vec![10,20,30,40,50]);
        assert_eq!(ret, 150);
        let ret = max_ascending_sum(vec![12,17,15,13,10,11,12]);
        assert_eq!(ret, 33);
    }
}