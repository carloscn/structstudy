
pub fn count_elements(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if nums.len() < 1 {
        return ret;
    }
    let mut max_val:i32 = i32::MIN;
    let mut min_val:i32 = i32::MAX;

    for i in 0..nums.len() {
        max_val = max_val.max(nums[i]);
        min_val = min_val.min(nums[i]);
    }

    for i in 0..nums.len() {
        if nums[i] > min_val && nums[i] < max_val {
            ret += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = count_elements(vec![11,7,2,15]);
        assert_eq!(ret, 2);

        let ret = count_elements(vec![-3,3,3,90]);
        assert_eq!(ret, 2);
    }
}