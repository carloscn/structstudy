
pub fn check(nums: Vec<i32>) -> bool
{
    if nums.len() < 1 {
        return true;
    }

    // Find min value position
    let mut m_pos:usize = 0;
    for i in 0..nums.len() - 1 {
        if nums[i + 1] < nums[i] {
            m_pos = i + 1;
            break;
        }
    }

    // check array with rules
    for i in 0..nums.len() - 1 {
        if nums[(i + 1 + m_pos) % nums.len()] < nums[(i + m_pos) % nums.len()] {
            return false;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = check(vec![3,4,5,1,2]);
        assert_eq!(ret, true);
        let ret = check(vec![2,1,3,4]);
        assert_eq!(ret, false);
        let ret = check(vec![1,2,3]);
        assert_eq!(ret, true);
    }
}