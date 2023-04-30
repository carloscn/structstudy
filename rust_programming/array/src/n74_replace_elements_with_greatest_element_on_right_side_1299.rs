
pub fn replace_elements(arr: Vec<i32>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];

    if arr.len() < 1 {
        return ret;
    }

    let mut max_val:i32 = -1;
    for i in 0..(arr.len() - 1) {
        let e = arr[arr.len() - i - 1];
        ret.insert(0, max_val);
        if e > max_val {
            max_val = e;
        }
    }
    ret.insert(0, max_val);

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = replace_elements(vec![17,18,5,4,6,1]);
        assert_eq!(ret, vec![18,6,6,6,1,-1]);
        let mut ret = replace_elements(vec![400]);
        assert_eq!(ret, vec![-1]);
    }
}