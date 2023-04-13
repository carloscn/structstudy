
pub fn duplicate_zeros(arr: &mut Vec<i32>)
{
    let mut i:usize = 0;
    let in_len:usize = arr.len();
    let array:Vec<i32> = arr.clone();

    arr.clear();
    while arr.len() < in_len {
        if array[i] != 0 {
            arr.push(array[i]);
        } else {
            arr.push(0);
            if arr.len() < in_len {
                arr.push(0);
            }
        }
        i += 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut arr = vec![1,0,2,3,0,4,5,0];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![1,0,0,2,3,0,0,4]);
    }

    #[test]
    fn test_duplicate_zeros() {
        let mut arr = vec![1, 0, 2, 3, 0, 4, 5, 0];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![1, 0, 0, 2, 3, 0, 0, 4]);

        let mut arr = vec![1, 2, 3];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![1, 2, 3]);

        let mut arr = vec![0, 0, 0, 0, 0, 0];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![0, 0, 0, 0, 0, 0]);

        let mut arr = vec![0, 1, 7, 6, 0, 2, 0, 7];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![0, 0, 1, 7, 6, 0, 0, 2]);

        let mut arr = vec![8, 4, 5, 0, 0, 0, 0, 7];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![8, 4, 5, 0, 0, 0, 0, 0]);

        let mut arr = vec![1, 0, 0, 0, 0, 0, 0, 0];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![1, 0, 0, 0, 0, 0, 0, 0]);

        let mut arr = vec![0, 0, 0, 0, 0, 0, 0, 1];
        duplicate_zeros(&mut arr);
        assert_eq!(arr, vec![0, 0, 0, 0, 0, 0, 0, 0]);
    }
}