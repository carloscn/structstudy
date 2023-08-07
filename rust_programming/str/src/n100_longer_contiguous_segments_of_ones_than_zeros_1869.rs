
pub fn check_zero_ones(s: &str) -> bool
{
    if s.len() < 1 {
        return false;
    }

    let s_v:Vec<char> = s.chars().collect();
    let (mut one_count, mut zero_count,
         mut max_one_count, mut max_zero_count) =
        (0usize, 0usize, usize::MIN, usize::MIN);

    for i in 0..s_v.len() - 1 {
        if s_v[i] == s_v[i + 1] && s_v[i] == '1' {
            one_count += 1;
            max_one_count = one_count.max(max_one_count);
        } else if s_v[i] == s_v[i + 1] && s_v[i] == '0' {
            zero_count += 1;
            max_zero_count = zero_count.max(max_zero_count);
        } else if s_v[i] != s_v[i + 1] {
            one_count = 0;
            zero_count = 0;
        }
    }

    return max_one_count > max_zero_count;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = check_zero_ones("1101");
        assert_eq!(ret, true);
        let ret = check_zero_ones("111000");
        assert_eq!(ret, false);
        let ret = check_zero_ones("110100010");
        assert_eq!(ret, false);
    }
}