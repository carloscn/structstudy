
pub fn find_lucky(arr: Vec<i32>) -> i32
{
    let mut ret:i32 = -1;

    if arr.len() < 1 {
        return ret;
    }

    let mut count:i32 = 1;
    let mut arr_dup = arr.clone();

    arr_dup.sort();
    arr_dup.push(arr_dup[0] - 1);
    for i in 1..arr_dup.len() {
        if arr_dup[i - 1] == arr_dup[i] {
            count += 1;
        } else {
            if count == arr_dup[i - 1] {
                ret = count;
            }
            count = 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = find_lucky(vec![2,2,3,4]);
        assert_eq!(ret, 2);
        let ret = find_lucky(vec![1,2,2,3,3,3]);
        assert_eq!(ret, 3);
        let ret = find_lucky(vec![2,2,2,3,3]);
        assert_eq!(ret, -1);
        let ret = find_lucky(vec![5]);
        assert_eq!(ret, -1);
        let ret = find_lucky(vec![7,7,7,7,7,7,7]);
        assert_eq!(ret, 7);
    }
}