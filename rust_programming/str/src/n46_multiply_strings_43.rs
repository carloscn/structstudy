

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_single_multi() {
        let mut ret = single_multi(&"9999".to_string(), '4');
        assert_eq!(ret, "39996");

        ret = single_multi(&"7777".to_string(), '8');
        assert_eq!(ret, "62216");

        ret = single_multi(&"9999999".to_string(), '2');
        assert_eq!(ret, "19999998");

        ret = single_multi(&"78".to_string(), '9');
        assert_eq!(ret, "702");

        ret = single_multi(&"123456789".to_string(), '6');
        assert_eq!(ret, "740740734");
    }
}

fn single_multi(in_str:&String, b:char) -> String
{
    let mut ret_str:String = String::new();
    let in_len:usize = (*in_str).len();
    let mut in_str_dup:String = String::from(in_str);
    let mut i:usize = 0;
    let mut b_int:i32 = ((b as u8) - ('0' as u8)) as i32;
    let mut p:i32 = 0;
    let mut c:i32 = 0;

    if 0 == in_len {
        return ret_str;
    }

    let in_str_int:Vec<i32> = in_str_dup.chars().
                                map(|x| x.to_digit(10).unwrap() as i32).collect();

    while i < in_len {
        c = b_int * in_str_int[in_len - i- 1] + c;
        p = c % 10;
        c = c / 10;
        ret_str.push(((p as u8) + ('0' as u8)) as char);
        i += 1;
    }

    if c != 0 {
        ret_str.push(((c as u8) + ('0' as u8)) as char);
    }

    utils::str::reverse(&mut ret_str);

    return ret_str;
}

fn cross_add(a_str:&String, b_str:&String, index:usize) -> String
{
    let mut ret_str:String = String::new();
    let a_len:usize = (*a_str).len();
    let b_len:usize = (*b_str).len();
    let max_len:usize = utils::num::max(a_len, b_len);

    if 0 == a_len || 0 == b_len {
        return ret_str;
    }



    return ret_str;
}
