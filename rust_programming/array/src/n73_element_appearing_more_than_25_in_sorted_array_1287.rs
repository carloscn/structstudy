
pub fn find_special_integer(arr: Vec<i32>) -> i32
{
    if arr.len() < 1 {
        return 0;
    }
    let mut count = 0;

    for i in 0..arr.len() - 1 {
        if arr[i] == arr[i + 1] {
            count += 1;
            if count as f64 / arr.len() as f64 >= 0.25_f64 {
                return arr[i];
            }
        } else {
            count = 0;
        }
    }

    return 0;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = find_special_integer(vec![1,2,2,6,6,6,6,7,10]);
        assert_eq!(ret, 6);
    }
}