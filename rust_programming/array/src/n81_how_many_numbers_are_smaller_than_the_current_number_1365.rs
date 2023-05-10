
pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32>
{
    if nums.len() < 1 {
        return nums;
    }

    let mut ret:Vec<i32> = vec![];

    for i in 0..nums.len() {
        let mut count:i32 = 0;
        for j in 0..nums.len() {
            if i != j && nums[i] > nums[j] {
                count += 1;
            }
        }
        ret.push(count);
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = smaller_numbers_than_current(vec![8,1,2,2,3]);
        assert_eq!(ret, vec![4,0,1,1,3]);
        let ret = smaller_numbers_than_current(vec![6,5,4,8]);
        assert_eq!(ret, vec![2,1,0,3]);
        let ret = smaller_numbers_than_current(vec![7,7,7,7]);
        assert_eq!(ret, vec![0,0,0,0]);
    }
}