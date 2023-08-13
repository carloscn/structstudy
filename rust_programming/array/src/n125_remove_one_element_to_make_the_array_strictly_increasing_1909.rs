
pub fn can_be_increasing(nums: Vec<i32>) -> bool
{
    if nums.len() < 1 {
        return false;
    }
    let mut ret:bool = false;
    let mut i:usize = 0;

    while i < nums.len() - 1 {
        if nums[i + 1] - nums[i] <= 0 {
            if ret == false &&
               i >= 1 &&
               nums[i + 1] - nums[i - 1] >= 0 {
                ret = true;
            } else {
                return false;
            }
        }
        i += 1;
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = can_be_increasing(vec![1,2,10,5,7]);
        assert_eq!(ret, true);
        let ret = can_be_increasing(vec![2,3,1,2]);
        assert_eq!(ret, false);
        let ret = can_be_increasing(vec![1,1,1]);
        assert_eq!(ret, false);
    }
}