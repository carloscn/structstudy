
pub fn special_array(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if nums.len() < 1 {
        return ret;
    }

    for x in 0..nums.len() + 1 {
        let mut count = 0;
        for y in 0..nums.len() {
            if nums[y] >= x as i32 {
                count += 1;
            }
        }
        if count == x {
            ret = x as i32;
            break;
        }
    }
    if ret == 0 {
        ret = -1;
    }
    ret
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = special_array(vec![3,5]);
        assert_eq!(ret, 2);
        let mut ret = special_array(vec![0,0]);
        assert_eq!(ret, -1);
        let mut ret = special_array(vec![0,4,3,0,4]);
        assert_eq!(ret, 3);
    }
}