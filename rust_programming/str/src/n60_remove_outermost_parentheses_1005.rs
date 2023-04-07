
pub fn remove_outer_parentheses(s: String) -> String
{
    let mut ret_str = String::new();

    if s.len() < 1 {
        return ret_str;
    }

    let s_char_vec:Vec<char> = s.chars().collect();
    let mut s_stack:Vec<char> = vec![];
    let mut i:usize = 0;
    let mut start:usize = 1;

    while i < s.len() {
        let c = s_char_vec[i];
        if (s_stack.len() > 0) &&
           ('(' == s_stack[s_stack.len() - 1]) &&
           (')' == c) {
            s_stack.pop();
        } else {
            s_stack.push(c);
        }

        if s_stack.is_empty() {

            for j in start..i {
                print!("{} ", s_char_vec[j]);
                ret_str.push(s_char_vec[j]);
            }
            start = i + 2;
        }
        i += 1;
    }

    return ret_str;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let s = "(()())(())(()(()))".to_string();
        let ret = remove_outer_parentheses(s);
        assert_eq!(ret, "()()()()(())".to_string());
    }
}