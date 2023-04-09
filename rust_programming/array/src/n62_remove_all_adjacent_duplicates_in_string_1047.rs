
pub fn remove_duplicates(s: String) -> String
{
    if s.len() < 1 {
        return s;
    }

    let s_vec:Vec<char> = s.chars().collect();
    let mut t_vec:Vec<char> = vec![];

    for e in s_vec {
        if (!t_vec.is_empty()) &&
           (e == t_vec[t_vec.len() - 1]) {
            t_vec.pop();
        } else {
            t_vec.push(e);
        }
    }

    return t_vec.iter().collect::<String>();
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let ret = remove_duplicates("abbaca".to_string());
        assert_eq!(ret, "ca".to_string());
    }

    #[test]
    fn test_empty_string() {
        let s = String::new();
        assert_eq!(remove_duplicates(s), String::new());
    }

    #[test]
    fn test_no_duplicates() {
        let s = String::from("abcde");
        assert_eq!(remove_duplicates(s), String::from("abcde"));
    }

    #[test]
    fn test_all_duplicates() {
        let s = String::from("aaaaa");
        assert_eq!(remove_duplicates(s), String::from("a"));
    }

    #[test]
    fn test_some_duplicates() {
        let s = String::from("abbaca");
        assert_eq!(remove_duplicates(s), String::from("ca"));
    }
    #[test]
    fn test_single_character() {
        let s = String::from("a");
        assert_eq!(remove_duplicates(s), String::from("a"));
    }

    #[test]
    fn test_two_duplicate_characters() {
        let s = String::from("aa");
        assert_eq!(remove_duplicates(s), String::from(""));
    }

    #[test]
    fn test_whitespace() {
        let s = String::from("a b c d e");
        assert_eq!(remove_duplicates(s), String::from("a b c d e"));
    }

    #[test]
    fn test_punctuation() {
        let s = String::from("hello, world!");
        assert_eq!(remove_duplicates(s), String::from("heo, world!"));
    }
}