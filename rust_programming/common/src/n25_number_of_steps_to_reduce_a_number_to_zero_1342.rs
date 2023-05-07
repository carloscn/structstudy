
pub fn number_of_steps(num: i32) -> i32
{
    if num == 0 {
        return num;
    }

    let mut e = num;
    let mut ret = 0;

    while e != 0 {
        if e & 1 == 0 {
            e /= 2;
        } else {
            e -= 1;
        }
        ret += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let ret = number_of_steps(14);
        assert_eq!(ret, 6);
        let ret = number_of_steps(8);
        assert_eq!(ret, 4);
        let ret = number_of_steps(123);
        assert_eq!(ret, 12);
    }
}