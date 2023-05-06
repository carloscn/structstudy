
fn is_palin_vec(s_in:&Vec<char>, len:usize) -> bool
{
    if len < 3 {
        return true;
    }

    for i in 0..(len / 2 as usize) {
        if s_in[i] != s_in[len - 1 - i] {
            return false;
        }
    }

    return true;
}

pub fn remove_palindrome_sub(s: String) -> i32
{
    let mut ret:i32 = 0;
    let mut s_vec:Vec<char> = s.chars().collect();

    if is_palin_vec(&s_vec, s_vec.len()) {
        return 1;
    } else {
        return 2;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let ret = remove_palindrome_sub("ababa".to_string());
        assert_eq!(ret, 1);
        let ret = remove_palindrome_sub("baabb".to_string());
        assert_eq!(ret, 2);
        let ret = remove_palindrome_sub("abb".to_string());
        assert_eq!(ret, 2);
    }
}