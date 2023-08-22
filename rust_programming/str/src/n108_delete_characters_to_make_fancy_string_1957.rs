
pub fn make_fancy_string(s: &str) -> String
{
    if s.len() < 1 {
        return s.to_string();
    }

    let mut s_v:Vec<char> = s.chars().collect();
    let mut c:usize = 1;

    s_v.push(' ');
    let len = s_v.len();
    for i in 0..len - 1 {
        if s_v[i] == s_v[i + 1] {
            c += 1;
        } else {
            if c >= 3 {
                for j in 0..c - 2 {
                    s_v[i - j] = ' ';
                }
            }
            c = 1;
        }
    }

    return s_v.into_iter().filter(|x| *x != ' ').collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = make_fancy_string("leeetcode");
        assert_eq!(ret, "leetcode".to_string());
        let ret = make_fancy_string("aaabaaaa");
        assert_eq!(ret, "aabaa".to_string());
        let ret = make_fancy_string("aab");
        assert_eq!(ret, "aab".to_string());
    }
}