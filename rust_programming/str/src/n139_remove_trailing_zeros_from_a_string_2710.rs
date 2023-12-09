
pub fn remove_trailing_zeros(num: &str) -> String
{
    let mut ret:String = String::new();
    if num.len() < 1 {
        return ret;
    }

    ret = num.trim_end_matches('0').to_string();

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = remove_trailing_zeros("12340000");
        assert_eq!(ret, "1234".to_string());

        let ret = remove_trailing_zeros("51230100");
        assert_eq!(ret, "512301".to_string());

        let ret = remove_trailing_zeros("123");
        assert_eq!(ret, "123".to_string());
    }
}