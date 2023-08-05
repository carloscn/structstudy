
pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32
{
    if nums.len() < 1 {
        return -1;
    }

    if nums[start as usize] == target {
        return 0;
    }

    let mut i:i32 = start + 1;
    let mut j:i32 = start;
    let len:i32 = nums.len() as i32;

    while i <= len || j >= 0 {
        if i < len && nums[i as usize] == target {
            return i - start;
        }
        i += 1;

        if j >= 0 && nums[j as usize] == target {
            return start - j;
        }
        j -= 1;
    }

    return -1;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = get_min_distance(vec![1,2,3,4,5], 5, 3);
        assert_eq!(ret, 1);
        let ret = get_min_distance(vec![1], 1, 0);
        assert_eq!(ret, 0);
        let ret = get_min_distance(vec![1,1,1,1,1,1,1,1,1,1], 1, 0);
        assert_eq!(ret, 0);
    }
}