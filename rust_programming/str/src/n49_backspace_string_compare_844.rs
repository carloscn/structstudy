
fn _convert(in_str:&String) -> String
{
    let v_char = (*in_str).chars();
    let mut ret_str = String::new();

    for i in v_char {
        if i != '#' {
            ret_str.push(i);
        } else {
            ret_str.pop();
        }
    }

    return ret_str;
}

fn back_string_compare(str1:&String, str2:&String) -> bool
{
    let a = _convert(str1);
    let b = _convert(str2);

    if a == b {
        return true;
    }

    return false;
}

#[cfg(test)]
mod tests {
    use super::*;

    //            "0123456789abcdef"
    // Input: s = "ab#c", t = "ad#c"
    // Output: true
    #[test]
    pub fn test_position_of_larget_groups1() {
        let ret = back_string_compare(&"ab#c".to_string(), &"ad#c".to_string());
        assert_eq!(ret, true);
    }
}