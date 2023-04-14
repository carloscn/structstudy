
pub fn defang_i_paddr(address: String) -> String
{
    let mut ret_str:String = String::new();

    if address.len() < 1 {
        return ret_str;
    }

    let in_vec:Vec<char> = address.chars().collect();

    for e in &in_vec {
        if '.' != *e {
            ret_str.push(*e);
        } else {
            ret_str.push_str("[.]");
        }
    }

    return ret_str;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let ret = defang_i_paddr("1.1.1.1".to_string());
        assert_eq!(ret, "1[.]1[.]1[.]1".to_string());
    }

    #[test]
    fn test_defang_i_paddr() {
        assert_eq!(defang_i_paddr("1.1.1.1".to_string()), "1[.]1[.]1[.]1".to_string());
        assert_eq!(defang_i_paddr("255.100.50.0".to_string()), "255[.]100[.]50[.]0".to_string());
        assert_eq!(defang_i_paddr("127.0.0.1".to_string()), "127[.]0[.]0[.]1".to_string());
        assert_eq!(defang_i_paddr("192.168.1.1".to_string()), "192[.]168[.]1[.]1".to_string());
    }
}