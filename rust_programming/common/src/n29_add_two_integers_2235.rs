
pub fn sum(num1: i32, num2: i32) -> i32
{
    return num1 + num2;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_demo() {
        let ret = sum(12, 5);
        assert_eq!(ret, 17);

        let ret = sum(-10, 4);
        assert_eq!(ret, -6);
    }
}