pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32>
{
    let mut ret_vec:Vec<i32> = vec![];
    if nums.len() < 1 {
        return ret_vec;
    }

    let mut i:usize = 0;
    let mut j:usize = nums.len() - 1;

    while i != j {
        let a = nums[i] * nums[i];
        let b = nums[j] * nums[j];

        if a < b {
            ret_vec.insert(0,b);
            j -= 1;
        } else if a > b {
            ret_vec.insert(0, a);
            i += 1;
        }

        if a == b && i != j {
            ret_vec.insert(0, a);
            ret_vec.insert(0,b);
            j -= 1;
            i += 1;
        }
    }

    ret_vec.insert(0, nums[i] * nums[i]);

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let ret = sorted_squares(vec![-4,-1,0,3,10]);
        assert_eq!(ret, vec![0,1,9,16,100]);
    }

    #[test]
    fn test_sorted_squares_empty() {
        assert_eq!(sorted_squares(vec![]), vec![]);
    }

    #[test]
    fn test_sorted_squares_single_negative() {
        assert_eq!(sorted_squares(vec![-2]), vec![4]);
    }

    #[test]
    fn test_sorted_squares_single_positive() {
        assert_eq!(sorted_squares(vec![3]), vec![9]);
    }

    #[test]
    fn test_sorted_squares_only_negative() {
        assert_eq!(sorted_squares(vec![-4, -3, -2, -1]), vec![1, 4, 9, 16]);
    }

    #[test]
    fn test_sorted_squares_only_positive() {
        assert_eq!(sorted_squares(vec![1, 2, 3, 4]), vec![1, 4, 9, 16]);
    }

    #[test]
    fn test_sorted_squares_both_positive_and_negative() {
        assert_eq!(sorted_squares(vec![-3, -2, -1, 0, 1, 2, 3]), vec![0, 1, 1, 4, 4, 9, 9]);
    }
}