
pub fn find_middle_index(nums: Vec<i32>) -> i32
{
    if nums.len() < 3 {
        return -1;
    }

    let mut ret:i32 = -1;
    let mut sum_left:i32;
    let mut sum_right:i32;
    let left:usize = 0;
    let right:usize = nums.len();

    for mid in 1..nums.len() {
        sum_left = 0;
        sum_right = 0;

        for i in left..mid {
            sum_left += nums[i];
        }
        for i in (mid + 1)..right {
            sum_right += nums[i];
        }
        if sum_left == sum_right {
            ret = mid as i32;
            break;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = find_middle_index(vec![2,3,-1,8,4]);
        assert_eq!(ret, 3);
        let ret = find_middle_index(vec![1,-1,4]);
        assert_eq!(ret, 2);
        let ret = find_middle_index(vec![2,5]);
        assert_eq!(ret, -1);
    }
}