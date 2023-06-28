
pub fn get_maximum_generated(n: i32) -> i32
{
    if n == 0 {
        return n;
    }

    let len:usize = n as usize;
    let mut arr:Vec<i32> = vec![0; len + 1];

    arr[0] = 0;
    arr[1] = 1;

    for i in 1..((len/2) + (len&1)) {
        arr[(i * 2)] = arr[i];
        arr[(i * 2) + 1] = arr[i] + arr[i + 1];
    }

    let mut ret:i32 = i32::MIN;
    for e in arr {
        if e > ret {
            ret = e;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = get_maximum_generated(7);
        assert_eq!(ret, 3);
        let mut ret = get_maximum_generated(2);
        assert_eq!(ret, 1);
        let mut ret = get_maximum_generated(3);
        assert_eq!(ret, 2);
    }
}