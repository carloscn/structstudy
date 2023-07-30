use std::ops::Add;


pub fn truncate_sentence(s: &str, k: i32) -> String
{
    if s.len() < 1 || k == 0 {
        return s.to_string();
    }

    let mut ret:String = String::new();
    let mut count:i32 = 0;
    for e in s.split(' ') {
        if count < k {
            ret += e;
            ret.push(' ');
        } else {
            break;
        }
        count += 1;
    }

    ret.remove(ret.len() - 1);
    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = truncate_sentence("Hello how are you Contestant", 4);
        assert_eq!(ret, "Hello how are you".to_string());
        let ret = truncate_sentence("What is the solution to this problem", 4);
        assert_eq!(ret, "What is the solution".to_string());
        let ret = truncate_sentence("chopper is not a tanuki", 5);
        assert_eq!(ret, "chopper is not a tanuki".to_string());
    }
}