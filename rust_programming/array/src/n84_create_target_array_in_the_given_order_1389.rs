
pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32>
{
    if nums.len() < 1 || index.len() < 1 {
        return nums;
    }

    let mut ret:Vec<i32> = vec![];
    let mut i:usize = 0;

    for num in nums {
        ret.insert(index[i] as usize, num);
        i += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = create_target_array(vec![0,1,2,3,4], vec![0,1,2,2,1]);
        assert_eq!(ret, vec![0,4,1,3,2]);
        let ret = create_target_array(vec![1,2,3,4,0], vec![0,1,2,3,0]);
        assert_eq!(ret, vec![0,1,2,3,4]);
        let ret = create_target_array(vec![1], vec![0]);
        assert_eq!(ret, vec![1]);
    }
}