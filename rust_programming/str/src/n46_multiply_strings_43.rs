
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
    let mut a_str_dup:String = String::from(a_str);
    let mut b_str_dup:String = String::from(b_str);
    let a_len:usize = (*a_str).len();
    let b_len:usize = (*b_str).len();
    let mut c:i32 = 0;
    let mut p:i32 = 0;

    let mut i:usize = 0;

    if 0 == a_len || 0 == b_len {
        return ret_str;
    }

    while i < index {
        b_str_dup.push('0');
        i += 1;
    }

    let mut a_int:Vec<i32> = a_str_dup.chars().map(|x| x.to_digit(10).unwrap() as i32).collect();
    let mut b_int:Vec<i32> = b_str_dup.chars().map(|x| x.to_digit(10).unwrap() as i32).collect();

    i = 0;
    let mut j:usize = 0;
    let max_len:usize = utils::num::max(a_int.len(), b_int.len());
    while i < max_len {
        let mut c1 = if i >= a_int.len() { 0 } else { a_int[a_int.len() - i - 1]};
        let mut c2 = if i >= b_int.len() { 0 } else { b_int[b_int.len() - i - 1]};
        c = c1 + c2 + c;
        p = c % 10;
        c = c / 10;
        ret_str.push(((p as u8) + ('0' as u8)) as char);
        i += 1;
    }

    utils::str::reverse(&mut ret_str);

    return ret_str;
}

fn multi_str(a_str:&String, b_str:&String) -> String
{
    let mut ret_str:String = String::new();
    let mut a_str_dup:String = String::from(a_str);
    let mut b_str_dup:String = String::from(b_str);
    let a_len:usize = (*a_str).len();
    let b_len:usize = (*b_str).len();
    let mut i:usize = 1;

    if a_len < b_len {
        return ret_str;
    }

    let mut b:Vec<char> = b_str_dup.chars().map(|x| x as char).collect();
    let mut ret_1 = single_multi(&a_str_dup, b[b.len() - 1]);
    let mut ret_2:String = String::new();

    while i < b.len() {
        ret_2 = single_multi(&a_str_dup, b[b.len() - i - 1]);
        ret_1 = cross_add(&ret_1, &ret_2, i);
        i += 1;
    }

    ret_str = ret_1;
    return ret_str;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_multi_str() {
        let ret = multi_str(&"1859".to_string(), &"185".to_string());
        println!("{ret}");
    }

    #[test]
    pub fn test_cross_add() {
        let mut a:String = String::new();
        let mut b:String = String::new();
        let mut ret;

        a.push_str(       "45666");
        b.push_str("112111993");
        ret = cross_add(&a, &b, 3);
        assert_eq!(ret, "112112038666".to_string());

        a.clear();
        b.clear();
        a.push_str(  "12345");
        b.push_str("12345");
        ret = cross_add(&a, &b, 2);
        assert_eq!(ret, "1246845".to_string());

    }
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
