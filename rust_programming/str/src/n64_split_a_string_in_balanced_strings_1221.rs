
pub fn balanced_string_split(s: String) -> i32
{
    let mut ret:i32 = 0;
    if s.len() < 1 {
        return ret;
    }

    let mut s_stack:Vec<char> = vec![];
    let s_chars:Vec<char> = s.chars().collect();
    let mut is_poped:bool = false;

    for e in s_chars {
        if s_stack.is_empty() {
            s_stack.push(e);
        } else {
            if e != s_stack[s_stack.len() - 1] {
                s_stack.pop();
                if s_stack.is_empty() {
                    ret += 1;
                    is_poped = false;
                } else {
                    is_poped = true;
                }
            } else {
                if is_poped {
                    return ret + 1;
                } else {
                    s_stack.push(e);
                }
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let ret = balanced_string_split("RLRRRLLRLL".to_string());
        assert_eq!(ret, 2);
        let ret = balanced_string_split("RLRRLLRLRL".to_string());
        assert_eq!(ret, 4);
        let ret = balanced_string_split("LLLLRRRR".to_string());
        assert_eq!(ret, 1);
    }
}