
// abcdefg
// abedcfg

// abcdabcd
// abcdabcd
fn is_buddy_string(a:&String, b:&String) -> bool
{
    let mut a_s:Vec<char> = String::from(a).chars().collect();
    let mut b_s:Vec<char> = String::from(b).chars().collect();
    let mut an:Vec<char> = vec![];
    let mut bn:Vec<char> = vec![];
    let mut i:usize = 0;

    if a_s.len() != b_s.len() {
        return false;
    }

    if a_s == b_s {
        for e in &a_s {
            if utils::str::is_contains_repeat_element(a, *e) {
                return true;
            }
        }
    }

    while i < a_s.len() {
        if a_s[i] != b_s[i] {
            an.push(a_s[i]);
            bn.push(b_s[i]);
        }
        i += 1;
    }

    if an.len() == 0 || bn.len() == 0{
        return false;
    }

    an.sort();
    bn.sort();

    return an == bn;
}


#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    pub fn test_buddy_string() {
        let mut ret = is_buddy_string(&"abcdefg".to_string(), &"abedcfg".to_string());
        assert_eq!(ret, true);

        ret = is_buddy_string(&"ab".to_string(), &"ba".to_string());
        assert_eq!(ret, true);

        ret = is_buddy_string(&"aa".to_string(), &"aa".to_string());
        assert_eq!(ret, true);

        ret = is_buddy_string(&"ab".to_string(), &"ab".to_string());
        assert_eq!(ret, false);
    }
}