
pub fn smallest_even_multiple(n: i32) -> i32
{
    let mut ret:i32 = n;

    while !((ret % 2) == 0 && (ret % n) == 0) {
        ret += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_demo() {
        let ret = smallest_even_multiple(5);
        assert_eq!(ret, 10);

        let ret = smallest_even_multiple(6);
        assert_eq!(ret, 6);
    }
}