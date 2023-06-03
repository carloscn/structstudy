
pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32
{
    if arr.len() < 3 {
        return 0;
    }

    let mut ret:i32 = 0;

    for i in 0..arr.len() - 2 {
        for j in (i + 1)..arr.len() - 1 {
            for k in (j + 1)..arr.len() {
                if i32::abs(arr[i] - arr[j]) <= a &&
                   i32::abs(arr[j] - arr[k]) <= b &&
                   i32::abs(arr[i] - arr[k]) <= c {
                    ret += 1;
                }
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
        let mut ret = count_good_triplets(vec![3,0,1,1,9,7], 7, 2, 3);
        assert_eq!(ret, 4);
        let mut ret = count_good_triplets(vec![1,1,2,2,3], 0, 0, 3);
        assert_eq!(ret, 0);
    }
}