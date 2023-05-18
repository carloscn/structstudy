
pub fn reformat(s: String) -> String
{
    if s.is_empty() {
        return s;
    }

    let mut fin:Vec<char> = vec![];
    let mut sv:Vec<char> = s.chars().collect();

    sv.sort();
    for i in 0..sv.len() / 2 {
        if sv[i].is_numeric() &&
           sv[sv.len() - i - 1].is_alphabetic() {
            fin.push(sv[i]);
            fin.push(sv[sv.len() - i - 1]);
        } else {
            return String::new();
        }
    }

    if sv.len() & 1 == 1 {
        if sv[sv.len()/2].is_numeric() {
            fin.push(sv[sv.len()/2]);
        } else {
            fin.insert(0, sv[sv.len()/2]);
        }
    }

    let ret:String = fin.into_iter().collect();

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = reformat("a0b1c2".to_string());
        assert_eq!(ret, "0c1b2a".to_string());
        let ret = reformat("leetcode".to_string());
        assert_eq!(ret, "".to_string());
        let ret = reformat("1229857369".to_string());
        assert_eq!(ret, "".to_string());
        let ret = reformat("covid2019".to_string());
        assert_eq!(ret, "c0v1o2i9d".to_string());
        let ret = reformat("ab123".to_string());
        assert_eq!(ret, "1b2a3".to_string());
    }
}