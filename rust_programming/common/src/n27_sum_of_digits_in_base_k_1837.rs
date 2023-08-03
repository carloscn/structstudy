
pub fn sum_base(n: i32, k: i32) -> i32
{
    let mut ret:i32 = 0;
    let mut s:i32 = n;

    while s != 0 {
        ret += s % k;
        s /= k;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_demo() {
        let ret = sum_base(34, 6);
        assert_eq!(ret, 9);
        let ret = sum_base(10, 10);
        assert_eq!(ret, 1);
    }
}