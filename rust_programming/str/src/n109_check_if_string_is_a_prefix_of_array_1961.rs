
pub fn is_prefix_string(s: &str, words: Vec<&str>) -> bool
{
    if s.len() < 1 && words.len() < 1 {
        return false;
    }

    let temp_str:Vec<char> = words.into_iter()
                                  .fold( vec![], |mut c, x| {
                                        c.append(&mut x.chars().collect());
                                        c
                                   }
    );

    let s_str:Vec<char> = s.chars().collect();

    for i in 0..s_str.len() {
        if temp_str[i] != s_str[i] {
            return false;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = is_prefix_string("iloveleetcode", vec!["i","love","leetcode","apples"]);
        assert_eq!(ret, true);
        let ret = is_prefix_string("iloveleetcode", vec!["apples","i","love","leetcode"]);
        assert_eq!(ret, false);
    }
}