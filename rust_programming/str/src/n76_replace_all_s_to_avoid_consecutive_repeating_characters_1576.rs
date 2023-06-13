
pub fn modify_string(s: String) -> String
{
    if s.is_empty() {
        return s;
    }

    let mut ret_vec:Vec<char> = s.chars().collect();

    for i in 0..ret_vec.len() {
        if ret_vec[i] == '?' {
            for j in 0..26u8 {
                let select:char = ('a' as u8 + j) as char;
                if (i > 0 && ret_vec[i - 1] == select) ||
                   (i < ret_vec.len() && ret_vec[i + 1] == select) {
                    continue;
                }
                ret_vec[i] = select;
                break;
            }
        }
    }

    let ret_str:String = ret_vec.iter().collect();

    return ret_str;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = modify_string("?zs".to_string());
        assert_eq!(ret, "azs".to_string());
        let ret = modify_string("ubv?w".to_string());
        assert_eq!(ret, "ubvaw".to_string());
    }
}