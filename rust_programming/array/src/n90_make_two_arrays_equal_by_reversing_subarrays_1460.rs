
pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool
{
    if target.is_empty() ||
       target.len() != arr.len() {
        return true;
    }

    let max_len:i32 = *target.iter().max().unwrap();
    if max_len != *arr.iter().max().unwrap() {
        return false;
    }

    let mut dup_target:Vec<i32> = vec![0; max_len as usize + 1];

    for i in 0..target.len() {
        dup_target[target[i] as usize] += 1;
        dup_target[arr[i] as usize] -= 1;
    }

    for i in 0..target.len() {
        if dup_target[i] != 0 {
            return false;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = can_be_equal(vec![1,2,3,4], vec![2,4,1,3]);
        assert_eq!(ret, true);
        let mut ret = can_be_equal(vec![7], vec![7]);
        assert_eq!(ret, true);
        let mut ret = can_be_equal(vec![3,7,9], vec![3,7,11]);
        assert_eq!(ret, false);
    }
}