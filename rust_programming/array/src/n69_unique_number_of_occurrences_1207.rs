
pub fn unique_occurrences(arr: Vec<i32>) -> bool
{
    if (arr.len() < 1) ||
       (arr.len() == 2 && arr[0] != arr[1]) {
        return false;
    }

    let mut rep_count:Vec<usize> = vec![];
    let mut arr_dup = arr.clone();
    let mut i:usize = 0;
    let mut count:usize = 0;

    arr_dup.sort();

    while i < arr.len() - 1 {
        if arr_dup[i] == arr_dup[i + 1] {
            count += 1;
        } else {
            if rep_count.contains(&count) {
                return false;
            } else {
                rep_count.push(count);
            }
            count = 0;
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
        let mut ret = unique_occurrences(vec![-3,0,1,-3,1,1,1,-3,10,0]);
        assert_eq!(ret, true);

        ret = unique_occurrences(vec![1, 2]);
        assert_eq!(ret, false);
    }

    #[test]
    fn test_unique_occurrences() {
        // Test case 1
        let arr1 = vec![1, 2, 2, 1, 1, 3];
        assert_eq!(unique_occurrences(arr1), true);

        // Test case 2
        let arr2 = vec![1, 2];
        assert_eq!(unique_occurrences(arr2), false);

        // Test case 3
        let arr3 = vec![-3, 0, 1, -3, 1, 1, 1, -3, 10, 0];
        assert_eq!(unique_occurrences(arr3), true);

        // Test case 4
        let arr4 = vec![1, 1, 2, 2, 2, 3];
        assert_eq!(unique_occurrences(arr4), true);
    }
}