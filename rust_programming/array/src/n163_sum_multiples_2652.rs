
pub fn sum_of_multiples(n: i32) -> i32
{
    let mut ret = 0;
    if n == 0 {
        return ret;
    }

    for i in 1..(n + 1) {
        if (i % 3 == 0) || (i % 5 == 0) || (i % 7 == 0) {
            ret += i;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = sum_of_multiples(7);
        assert_eq!(ret, 21);

        let ret = sum_of_multiples(10);
        assert_eq!(ret, 40);

        let ret = sum_of_multiples(9);
        assert_eq!(ret, 30);
    }
}