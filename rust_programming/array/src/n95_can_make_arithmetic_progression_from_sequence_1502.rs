
pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool
{
    if arr.len() < 1 {
        return false;
    }

    let mut d:i32 = 0;

    let mut arr_dup = arr.clone();
    for i in 0..arr_dup.len() {
        for j in 0..arr_dup.len() - i - 1 {
            if arr_dup[j] < arr_dup[j + 1] {
                let t = arr_dup[j];
                arr_dup[j] = arr_dup[j + 1];
                arr_dup[j + 1] = t;
            }
        }
    }

    for i in 0..arr_dup.len() {
        if i == 0 {
            d = arr_dup[i] - arr_dup[i + 1];
        } else if i < arr_dup.len() - 1 {
            if arr_dup[i] - arr_dup[i + 1] != d {
                return false;
            }
        } else {
            return true;
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
        let ret = can_make_arithmetic_progression(vec![3,5,1]);
        assert_eq!(ret, true);
        let ret = can_make_arithmetic_progression(vec![1,2,4]);
        assert_eq!(ret, false);
    }
}