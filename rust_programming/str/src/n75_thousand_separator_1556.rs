
pub fn thousand_separator(n: i32) -> String
{
    let mut s_vec:Vec<char> = vec![];
    let mut dn:Vec<char> = i32::to_string(&n).chars().collect();
    let mut count:usize = 0;

    dn.reverse();

    for e in &dn {
        if count % 3 == 0 &&
           count != 0 &&
           count != dn.len() {
            s_vec.insert(0, '.');
        }
        s_vec.insert(0, *e);
        count += 1;
    }

    return s_vec.into_iter().collect::<String>();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let mut ret = thousand_separator(987);
        assert_eq!(ret, "987");
        let mut ret = thousand_separator(1234);
        assert_eq!(ret, "1.234");
        let mut ret = thousand_separator(123456789);
        assert_eq!(ret, "123.456.789");
        let mut ret = thousand_separator(0);
        assert_eq!(ret, "0");
    }
}