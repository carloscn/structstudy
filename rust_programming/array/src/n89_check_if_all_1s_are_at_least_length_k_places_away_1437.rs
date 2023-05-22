
pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool
{
    if nums.len() < 1 {
        return false;
    }

    let mut count_0:i32 = k + 1;

    for i in 0..nums.len() {
        if nums[i] == 1 {
            if count_0 < k {
                return false;
            }
            count_0 = 0;
        } else {
            count_0 += 1;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = k_length_apart(vec![1,0,0,0,1,0,0,1], 2);
        assert_eq!(ret, true);
        let ret = k_length_apart(vec![1,0,0,1,0,1], 2);
        assert_eq!(ret, false);
        let ret = k_length_apart(vec![1,1,1,1,1], 0);
        assert_eq!(ret, true);
        let ret = k_length_apart(vec![0,1,0,1], 1);
        assert_eq!(ret, true);
    }
}