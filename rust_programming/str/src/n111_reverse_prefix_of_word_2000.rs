
pub fn reverse_prefix(word: &str, ch: char) -> String
{
    if word.len() < 1 {
        return String::new();
    }

    let mut ret:Vec<char> = vec![];
    let mut t_v:Vec<char> = vec![];
    let w_v:Vec<char> = word.chars().collect();

    for i in 0..word.len() {
        if w_v[i] != ch {
            t_v.push(w_v[i]);
        } else {
            t_v.push(w_v[i]);
            break;
        }
    }

    if t_v.len() == w_v.len() {
        return w_v.iter().collect();
    }

    for i in 0..word.len() {
        if !t_v.is_empty() {
            ret.push(t_v.pop().unwrap());
            continue;
        }

        ret.push(w_v[i])
    }

    return ret.iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = reverse_prefix("abcdefd", 'd');
        assert_eq!(ret, "dcbaefd".to_string());
        let ret = reverse_prefix("xyxzxe", 'z');
        assert_eq!(ret, "zxyxxe".to_string());
        let ret = reverse_prefix("abcd", 'z');
        assert_eq!(ret, "abcd".to_string());
    }
}