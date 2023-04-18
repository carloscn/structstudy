
fn is_in_str(a: &String, b: &String) -> bool
{
    if a.len() < 1 || b.len() < 1 {
        return false;
    }

    let a_vec:Vec<char> = a.chars().collect();
    let mut b_dup:Vec<char> = b.clone().chars().collect();

    for e in a_vec {
        let p = b_dup.iter().position(|x| *x == e);
        if p == None {
            return false;
        } else {
            b_dup.remove(p.unwrap());
        }
    }

    return true;
}

pub fn count_characters(words: Vec<String>, chars: String) -> i32
{
    let mut ret = 0;

    if words.len() < 1 ||
       chars.len() < 1 {
        return ret;
    }

    for e in &words {
        if is_in_str(e, &chars) {
            ret += e.len() as i32;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let words = vec!["cat".to_string(),"bt".to_string(),"hat".to_string(),"tree".to_string()];
        let chars = "atach".to_string();
        let ret = count_characters(words, chars);
        assert_eq!(ret, 6);
    }
    #[test]
    fn test_1() {
        let words = vec!["cat".to_string(), "bt".to_string(), "hat".to_string(), "tree".to_string()];
        let chars = "atach".to_string();
        let expected = 6;
        assert_eq!(count_characters(words, chars), expected);
    }

    #[test]
    fn test_2() {
        let words = vec!["hello".to_string(), "world".to_string(), "leetcode".to_string()];
        let chars = "welldonehoneyr".to_string();
        let expected = 10;
        assert_eq!(count_characters(words, chars), expected);
    }

    #[test]
    fn test_3() {
        let words = vec!["abcdefg".to_string(), "hijklmnopqrs".to_string(), "tuvwxyz".to_string()];
        let chars = "abcdefghijklmnopqrstuvwxyz".to_string();
        let expected = 26;
        assert_eq!(count_characters(words, chars), expected);
    }

    #[test]
    fn test_4() {
        let words = vec!["a".to_string(), "b".to_string(), "c".to_string(), "d".to_string(), "e".to_string(), "f".to_string()];
        let chars = "abcdef".to_string();
        let expected = 6;
        assert_eq!(count_characters(words, chars), expected);
    }

    #[test]
    fn test_5() {
        let words = vec!["aaa".to_string(), "bbb".to_string(), "ccc".to_string(), "ddd".to_string()];
        let chars = "aabbccdd".to_string();
        let expected = 0;
        assert_eq!(count_characters(words, chars), expected);
    }
}