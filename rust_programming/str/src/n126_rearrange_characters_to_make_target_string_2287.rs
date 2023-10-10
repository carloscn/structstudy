
pub fn rearrange_characters(s: &str, target: &str) -> i32
{
    let mut ret:i32 = 0;
    if s.is_empty() || target.is_empty() || s.len() < target.len() {
        return ret;
    }

    let mut s_dup:Vec<char> = s.chars().collect();
    let t_dup:Vec<char> = target.chars().collect();
    let mut count_min_number:usize = usize::MAX;
    for i in 0..target.len() {
        let mut j:usize = 0;
        let mut count:usize = 0;
        let mut index:usize = 0;
        while j < s_dup.len() {
            if s_dup[j] == t_dup[i] {
                count += 1;
                index = j;
            }
            j += 1;
        }
        s_dup.remove(index);
        count_min_number = count.min(count_min_number);
    }

    ret = count_min_number as i32;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = rearrange_characters("ilovecodingonleetcode", "code");
        assert_eq!(ret, 2);
        let ret = rearrange_characters("abcba", "abc");
        assert_eq!(ret, 1);
        let ret = rearrange_characters("abbaccaddaeea", "aaaaa");
        assert_eq!(ret, 1);
    }
}