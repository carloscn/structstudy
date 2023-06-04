
pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32
{
    if arr.is_empty() {
        return 0;
    }

    let mut ret:i32 = 0;
    let mut j:usize = 0;
    let mut s:usize = 0;

    let mut ab:Vec<i32> = vec![];

    for i in 0..i32::MAX {
        if !arr.contains(&i) {
            ab.push(i);
            if ab.len() > k as usize {
                return ab.pop().unwrap();
            }
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
        let mut ret = find_kth_positive(vec![2,3,4,7,11], 5);
        assert_eq!(ret, 9);
        let mut ret = find_kth_positive(vec![1,2,3,4], 2);
        assert_eq!(ret, 6);
    }
}