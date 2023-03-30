
pub fn valid_mountain_array(arr: Vec<i32>) -> bool
{
    let mut i:usize = 0;
    let mut a_pos:usize = 0;
    let mut b_pos:usize;

    if arr.len() < 3 {
        return false;
    }

    b_pos = arr.len() - 1;

    while i < arr.len() - 1 {
        if arr[i] == arr[i + 1] ||
           arr[arr.len() - i - 1] == arr[arr.len() - i - 2] {
            return false;
        }

        if (arr[i] > arr[i + 1]) && (0 == a_pos) {
            if (0 == i) && (0 == a_pos) {
                return false;
            }
            a_pos = i;
        }

        if (arr[arr.len() - i - 1] > arr[arr.len() - i - 2]) &&
           ((arr.len() - 1) == b_pos) {
            if (0 == i) && (arr.len() - 1 == b_pos) {
                return false;
            }
            b_pos = arr.len() - i - 1;
        }

        if a_pos != 0 && b_pos != (arr.len() - 1) && a_pos != b_pos {
            return false;
        }

        i += 1;
    }

    return true;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let ret = valid_mountain_array(vec![0,3,2,1]);
        assert_eq!(ret, true);
    }
    #[test]
    fn test_valid_mountain_array() {
        // Case 1: Empty array
        assert_eq!(valid_mountain_array(vec![]), false);

        // Case 2: Array with only one element
        assert_eq!(valid_mountain_array(vec![1]), false);

        // Case 3: Array with two elements
        assert_eq!(valid_mountain_array(vec![1, 2]), false);

        // Case 4: Array with increasing elements only
        assert_eq!(valid_mountain_array(vec![1, 2, 3, 4, 5]), false);

        // Case 5: Array with decreasing elements only
        assert_eq!(valid_mountain_array(vec![5, 4, 3, 2, 1]), false);

        // Case 6: Array with increasing then decreasing elements
        assert_eq!(valid_mountain_array(vec![1, 2, 3, 2, 1]), true);

        // Case 7: Array with decreasing then increasing elements
        assert_eq!(valid_mountain_array(vec![5, 4, 3, 4, 5]), false);

        // Case 8: Array with a peak at the beginning
        assert_eq!(valid_mountain_array(vec![3, 2, 1]), false);

        // Case 9: Array with a peak at the end
        assert_eq!(valid_mountain_array(vec![1, 2, 3, 2]), true);
    }
}
