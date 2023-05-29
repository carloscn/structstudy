
pub fn running_sum(nums: Vec<i32>) -> Vec<i32>
{
    if nums.len() < 1 {
        return nums;
    }

    let mut ret:Vec<i32> = vec![];

    for i in 0..nums.len() {
        let mut e = 0;
        for j in 0..i + 1 {
            e += nums[j];
        }
        ret.push(e);
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = running_sum(vec![1,2,3,4]);
        assert_eq!(ret, vec![1,3,6,10]);
        let ret = running_sum(vec![1,1,1,1,1]);
        assert_eq!(ret, vec![1,2,3,4,5]);
        let ret = running_sum(vec![3,1,2,10,1]);
        assert_eq!(ret, vec![3,4,6,16,17]);
    }
}