
pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32>
{
    if nums.len() < 1 ||
       nums.len() & 0x01 == 1 {
        return nums;
    }

    let mut ret:Vec<i32> = vec![];
    let mut i:usize = 0;

    while i < nums.len() {
        let e = nums[nums.len() - i - 1];
        let times = nums[nums.len() - i - 2];
        for j in 0..times {
            ret.insert(0, e);
        }
        i += 2;
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = decompress_rl_elist(vec![1,2,3,4]);
        assert_eq!(ret, vec![2,4,4,4]);
        ret = decompress_rl_elist(vec![1,1,2,3]);
        assert_eq!(ret, vec![1,3,3]);
    }
}