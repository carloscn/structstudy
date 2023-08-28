
pub fn find_gcd(nums: Vec<i32>) -> i32
{
    if nums.len() < 1 {
        return 0;
    }

    let mut max_val:i32 = i32::MIN;
    let mut min_val:i32 = i32::MAX;

    for i in 0..nums.len() {
        max_val = max_val.max(nums[i]);
        min_val = min_val.min(nums[i]);
    }

    while max_val != min_val {
        if max_val > min_val {
            max_val -= min_val;
        }
        if max_val < min_val {
            min_val -= max_val;
        }
    }

    return max_val;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = find_gcd(vec![2,5,6,9,10]);
        assert_eq!(ret, 2);
        let ret = find_gcd(vec![7,5,6,8,3]);
        assert_eq!(ret, 1);
        let ret = find_gcd(vec![3,3]);
        assert_eq!(ret, 3);
    }
}