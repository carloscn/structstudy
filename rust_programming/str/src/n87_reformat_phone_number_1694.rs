
pub fn reformat_number(number: &str) -> String
{
    if number.len() < 1 {
        return number.to_string();
    }

    let nd:Vec<char> = number.chars().collect();
    let mut ret:Vec<char> = vec![];
    let mut count:usize = 0;

    for i in 0..nd.len() {
        if nd[i].is_numeric() {
            if count == 3 {
                ret.push('-');
                count = 0;
            }
            ret.push(nd[i]);
            count += 1;
        }
    }

    if ret[ret.len() - 2] == '-' {
        ret.remove(ret.len() - 2);
        ret.insert(ret.len() - 2, '-')
    }

    return ret.into_iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = reformat_number("1-23-45 6");
        assert_eq!(ret, "123-456".to_string());
        let ret = reformat_number("123 4-567");
        assert_eq!(ret, "123-45-67".to_string());
        let ret = reformat_number("123 4-5678");
        assert_eq!(ret, "123-456-78".to_string());
        let ret = reformat_number("12");
        assert_eq!(ret, "12".to_string());
        let ret = reformat_number("--17-5 229 35-39475 ");
        assert_eq!(ret, "175-229-353-94-75".to_string());
    }
}