
pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];

    for i in 0..n as usize {
        ret.push(nums[i]);
        ret.push(nums[n as usize + i]);
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = shuffle(vec![2,5,1,3,4,7], 3);
        assert_eq!(ret, vec![2,3,5,4,1,7]);
        let ret = shuffle(vec![1,2,3,4,4,3,2,1], 4);
        assert_eq!(ret, vec![1,4,2,3,3,2,4,1]);
        let ret = shuffle(vec![1,1,2,2], 2);
        assert_eq!(ret, vec![1,2,1,2]);
    }
}