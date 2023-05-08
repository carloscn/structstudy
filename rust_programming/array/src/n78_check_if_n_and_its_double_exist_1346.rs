
pub fn check_if_exist(arr: Vec<i32>) -> bool
{
    if arr.len() < 1 {
        return false;
    }

    let mut i:usize = 0;
    let mut j:usize;

    while i < arr.len() {
        j = 0;
        while j < arr.len() {
            if i != j && 2*arr[i] == arr[j] {
                return true;
            }
            j += 1;
        }
        i += 1;
    }

    return false;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = check_if_exist(vec![10,2,5,3]);
        assert_eq!(ret, true);

        ret = check_if_exist(vec![7,1,14,11]);
        assert_eq!(ret, true);

        ret = check_if_exist(vec![3,1,7,11]);
        assert_eq!(ret, false);
    }
}