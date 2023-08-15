
pub fn build_array(nums: Vec<i32>) -> Vec<i32>
{
    if nums.is_empty() {
        return nums;
    }

    let mut ret:Vec<i32> = vec![0; nums.len()];

    for i in 0..ret.len() {
        let e = nums[i] as usize;
        if e < nums.len() {
            ret[i] = nums[e];
        } else {
            return vec![];
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = build_array(vec![0,2,1,5,3,4]);
        assert_eq!(ret, vec![0,1,2,4,5,3]);
        let ret = build_array(vec![5,0,1,2,3,4]);
        assert_eq!(ret, vec![4,5,0,1,2,3]);
    }
}