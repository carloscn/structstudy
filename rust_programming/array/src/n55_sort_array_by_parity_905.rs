

pub fn sort_array_by_parity(nums: Vec<i32>) -> Vec<i32>
{
    let mut ret_vec:Vec<i32> = vec![];
    let mut i:usize = 0;

    for e in &nums {
        if 1 == *e & 1 {
            ret_vec.push(*e);
        } else {
            ret_vec.insert(i, *e);
            i += 1;
        }
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_empty_vector() {
        let nums: Vec<i32> = vec![];
        let expected: Vec<i32> = vec![];
        assert_eq!(sort_array_by_parity(nums), expected);
    }

    #[test]
    fn test_all_odd_numbers() {
        let nums: Vec<i32> = vec![1, 3, 5, 7];
        let expected: Vec<i32> = vec![1, 3, 5, 7];
        assert_eq!(sort_array_by_parity(nums), expected);
    }

    #[test]
    fn test_all_even_numbers() {
        let nums: Vec<i32> = vec![2, 4, 6, 8];
        let expected: Vec<i32> = vec![2, 4, 6, 8];
        assert_eq!(sort_array_by_parity(nums), expected);
    }

    #[test]
    fn test_mixed_numbers() {
        let nums: Vec<i32> = vec![3, 1, 2, 4];
        let expected: Vec<i32> = vec![2, 4, 3, 1];
        assert_eq!(sort_array_by_parity(nums), expected);
    }

    #[test]
    fn test_duplicate_numbers() {
        let nums: Vec<i32> = vec![3, 2, 1, 2];
        let expected: Vec<i32> = vec![2, 2, 3, 1];
        assert_eq!(sort_array_by_parity(nums), expected);
    }

}