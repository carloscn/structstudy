
pub fn find_the_distance_value(arr1: Vec<i32>, arr2: Vec<i32>, d: i32) -> i32
{
    let mut ret:i32 = 0;

    if arr1.len() < 1 || arr2.len() < 1 {
        return ret;
    }

    for m in &arr1 {
        let mut count = 0;
        for n in &arr2 {
            if i32::abs(*m - *n) > d {
                count += 1;
            } else {
                break;
            }
        }
        if count == arr2.len() {
            ret += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = find_the_distance_value(vec![4,5,8], vec![10,9,1,8], 2);
        assert_eq!(ret, 2);
        let ret = find_the_distance_value(vec![1,4,2,3], vec![-4,-3,6,10,20,30], 3);
        assert_eq!(ret, 2);
        let ret = find_the_distance_value(vec![2,1,100,3], vec![-5,-2,10,-3,7], 6);
        assert_eq!(ret, 1);
    }
}