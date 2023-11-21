
pub fn find_the_longest_balanced_substring(s: &str) -> i32
{
    let mut ret:i32 = 0;
    if s.len() < 1 {
        return ret;
    }

    let mut c_s:Vec<char> = s.chars().collect();
    let mut count:usize = 0;
    let mut i = 0;
    // 00111
    while i < c_s.len() {
        if c_s[i] != '1' {
            i += 1;
            count = 0;
            continue;
        } else {
            if i == 0 {
                i += 1;
                continue;
            }
            let mut j: i32 = (i - 1) as i32;
            while j >= 0 && i < c_s.len() && c_s[j as usize] == '0' && c_s[i] == '1' {
                count += 1;
                j -= 1;
                i += 1;
            }
            i += 1;
        }

        ret = ret.max(count as i32);
    }

    ret *= 2;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = find_the_longest_balanced_substring("010000111");
        assert_eq!(ret, 6);
        let ret = find_the_longest_balanced_substring("00111");
        assert_eq!(ret, 4);
        let ret = find_the_longest_balanced_substring("111");
        assert_eq!(ret, 0);
    }
}