
pub fn make_smallest_palindrome(s: &str) -> String
{
    let mut ret:String = String::new();
    if s.len() < 1 {
        return ret;
    }

    let mut sv:Vec<char> = s.chars().collect();;
    let mut i:usize = 0;
    let mut j:usize = sv.len() - 1;

    while i != j {
        if sv[i] != sv[j] {
            if sv[i] < sv[j] {
                sv[j] = sv[i];
            } else {
                sv[i] = sv[j];
            }
        }
        if i + 1 == j {
            break;
        }
        i += 1;
        j -= 1;
    }

    ret = sv.iter().collect();

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = make_smallest_palindrome("egcfe");
        assert_eq!(ret, "efcfe".to_string());

        let ret = make_smallest_palindrome("abcd");
        assert_eq!(ret, "abba".to_string());
    }
}