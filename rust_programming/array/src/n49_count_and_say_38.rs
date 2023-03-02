fn gen_str(in_str:&String) -> String
{
    let mut ret_str:String = String::new();
    let mut dup_in_str = String::from(in_str);
    let in_chars:Vec<char>;
    let mut i:usize = 0;
    let mut count:usize = 1;

    dup_in_str.push('\0');
    in_chars = dup_in_str.chars().collect();

    while i < in_str.len() {
        let e = &in_chars[i];
        let c = &in_chars[i + 1];
        if *e == *c {
            count += 1;
        } else {
            ret_str.push(char::from_digit(count as u32, 10).unwrap());
            ret_str.push(*e);
            count = 1;
        }
        i += 1;
    }

    return ret_str;

}

fn count_and_say(n:usize) -> String
{
    let mut ret_str:String = String::new();
    let mut i:usize = 1;

    if 0 == n {
        return ret_str;
    }

    ret_str.push('1');

    if 1 == n {
        return ret_str;
    }

    while i < n {
        ret_str = gen_str(&ret_str);
        i += 1;
    }

    return ret_str;
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_count_and_say() {
        let mut ret = count_and_say(4);
        assert_eq!(ret, "1211".to_string());

        ret = count_and_say(5);
        assert_eq!(ret, "111221".to_string());
    }
}