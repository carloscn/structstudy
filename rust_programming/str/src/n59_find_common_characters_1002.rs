use std::ops::Index;

fn is_contain_then_remove(in_str:&mut String, ch: char) -> bool
{
    if in_str.len() < 1 {
        return false;
    }

    let mut i:usize = 0;
    let in_chars:Vec<char> = in_str.chars().collect();

    for e in &in_chars {
        if *e == ch {
            in_str.remove(i);
            return true;
        }
        i += 1;
    }

    return false;
}

pub fn common_chars(words: Vec<String>) -> Vec<String>
{
    if words.len() < 1 {
        return vec![];
    }

    let mut ret_vec:Vec<String> = vec![];
    let mut word_dup:Vec<String> = words.clone();
    let mut char_push:bool = false;
    let mut count:usize = 0;
    let mut e:u8 = 'a' as u8;

    while e <= 'z' as u8 {
        for str in &mut word_dup {
            if !str.is_empty() {
                if is_contain_then_remove(str, e as char) == true {
                    count += 1;
                }
            }
            if count == words.len() {
                char_push = true;
            }
        }
        count = 0;

        if true == char_push {
            ret_vec.push((e as char).to_string());
            e = e - (1 as u8);
        }
        char_push = false;
        e += 1;
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let ret = common_chars(vec!["bella".to_string(),"label".to_string(),"roller".to_string()]);
        assert_eq!(ret, vec!["e".to_string(),"l".to_string(),"l".to_string()]);
    }

    #[test]
    fn test_common_chars() {
        assert_eq!(common_chars(vec!["bella".to_string(), "label".to_string(), "roller".to_string()]), vec!["e".to_string(), "l".to_string(), "l".to_string()]);
        assert_eq!(common_chars(vec!["cool".to_string(), "lock".to_string(), "cook".to_string()]), vec!["c".to_string(), "o".to_string()]);
        assert_eq!(common_chars(vec!["a".to_string(), "aa".to_string(), "aaa".to_string()]), vec!["a".to_string()]);
    }

    #[test]
    fn test_common_chars_more() {
        assert_eq!(common_chars(vec!["apple".to_string(), "lepmon".to_string(), "pear".to_string()]), vec!["e".to_string(), "p".to_string()]);
        assert_eq!(common_chars(vec!["hello".to_string(), "world".to_string()]), vec!["l".to_string(), "o".to_string()]);
        assert_eq!(common_chars(vec!["hello".to_string(), "hola".to_string(), "hallo".to_string()]), vec!["h".to_string(), "l".to_string(), "o".to_string()]);
    }
}