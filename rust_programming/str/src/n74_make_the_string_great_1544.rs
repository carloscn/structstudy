
fn is_uper_lower_same(a:&char, b:&char) -> bool
{
    let mut ret:bool = false;

    if (a.is_uppercase() && b.is_lowercase() && *a as u8 + 32u8 == *b as u8) ||
       (b.is_uppercase() && a.is_lowercase() && *b as u8 + 32u8 == *a as u8) {
        return true;
    }

    return false;
}

pub fn make_good(s: &str) -> String
{
    if s.is_empty() {
        return s.to_string();
    }

    let mut r_v:Vec<char> = vec![];
    let s_v:Vec<char> = s.chars().collect();

    for i in 0..s_v.len() {
        if r_v.is_empty() ||
           !is_uper_lower_same(&r_v[r_v.len() - 1], &s_v[i]) {
            r_v.push(s_v[i]);
        } else {
            r_v.pop();
        }
    }

    return r_v.into_iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = make_good("leEeetcode");
        assert_eq!(ret, "leetcode".to_string());
        let ret = make_good("abBAcC");
        assert_eq!(ret, "".to_string());
        let ret = make_good("s");
        assert_eq!(ret, "s".to_string());
    }
}