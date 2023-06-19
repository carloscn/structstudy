
pub fn max_depth(s: &str) -> i32
{
    let mut ret:i32 = 0;

    if s.is_empty() {
        return ret;
    }

    let mut t_vec:Vec<char> = vec![];
    let s_dup:Vec<char> = s.chars().collect();

    for e in s_dup {
        if e == '(' {
            t_vec.push(e);
            ret = ret.max(t_vec.len() as i32);
        } else if e == ')' {
            if !t_vec.is_empty() {
                t_vec.pop();
            } else {
                return 0;
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
        let ret = max_depth("(1+(2*3)+((8)/4))+1");
        assert_eq!(ret, 3);
        let ret = max_depth("(1)+((2))+(((3)))");
        assert_eq!(ret, 3);
    }
}