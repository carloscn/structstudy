
pub fn max_length_between_equal_characters(s: &str) -> i32
{
    if s.is_empty() {
        return 0;
    }

    let mut ret:i32 = 0;

    let s_vec:Vec<char> = s.chars().collect();

    let mut j:usize = 0;
    for i in 0..s_vec.len() / 2 {
        j = s_vec.len() - i - 1;
        if s_vec[i] == s_vec[j] {
            ret = (j - i - 1) as i32;
            return ret;
        }
    }

    return -1;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = max_length_between_equal_characters("aa");
        assert_eq!(ret, 0);
        let ret = max_length_between_equal_characters("abca");
        assert_eq!(ret, 2);
        let ret = max_length_between_equal_characters("cbzxy");
        assert_eq!(ret, -1);
        let ret = max_length_between_equal_characters("cabbac");
        assert_eq!(ret, 4);
    }
}