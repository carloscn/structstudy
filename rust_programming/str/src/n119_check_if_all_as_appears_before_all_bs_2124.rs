
pub fn check_string(s: &str) -> bool
{
    if s.len() < 1 {
        return false;
    }

    let s_vec:Vec<char> = s.chars().collect();
    let mut a_flag = false;

    for i in 0..s_vec.len() {
        let e = s_vec[s_vec.len() - i - 1];
        if e == 'a' {
            a_flag = true;
        } else if e == 'b' {
            if a_flag == true {
                return false;
            }
        } else {
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
        let ret = check_string("aaabbb");
        assert_eq!(ret, true);

        let ret = check_string("abab");
        assert_eq!(ret, false);

        let ret = check_string("bbb");
        assert_eq!(ret, true);
    }
}