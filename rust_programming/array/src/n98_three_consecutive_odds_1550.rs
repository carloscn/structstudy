
pub fn three_consecutive_odds(arr: Vec<i32>) -> bool
{
    if arr.len() < 3 {
        return false;
    }

    for i in 0..arr.len() - 2 {
        if arr[i] & 0x1 == 1 &&
           arr[i + 1] & 0x1 == 1 &&
           arr[i + 2] & 0x1 == 1 {
            return true;
        }
    }

    return false;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = three_consecutive_odds(vec![2,6,4,1]);
        assert_eq!(ret, false);
        let ret = three_consecutive_odds(vec![1,2,34,3,4,5,7,23,12]);
        assert_eq!(ret, true);
    }
}