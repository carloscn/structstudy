
pub fn max_product_difference(nums: Vec<i32>) -> i32
{
    if nums.len() < 4 {
        return 0;
    }

    let mut ret:i32 = 0;

    let (mut first_max, mut sec_max, mut first_min, mut sec_min) =
        (i32::MIN, i32::MIN + 1, i32::MAX, i32::MAX - 1);

    for i in 0..nums.len() {
        if nums[i] > first_max {
            sec_max = first_max;
            first_max = nums[i];
        } else if nums[i] <= first_max && nums[i] > sec_max {
            sec_max = nums[i];
        }

        if nums[i] < first_min {
            sec_min = first_min;
            first_min = nums[i];
        } else if nums[i] >= first_min && nums[i] < sec_min {
            sec_min = nums[i];
        }
    }

    ret = (first_max * sec_max) - (first_min * sec_min);

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = max_product_difference(vec![5,6,2,7,4]);
        assert_eq!(ret, 34);
        let ret = max_product_difference(vec![4,2,5,9,7,4,8]);
        assert_eq!(ret, 64);
    }
}