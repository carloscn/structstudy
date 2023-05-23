
pub fn max_power(s: String) -> i32
{
    if s.is_empty() {
        return 0;
    }

    let mut count:i32 = 1;
    let mut max_count:i32 = 0;
    let s_vec:Vec<char> = s.chars().collect();

    for i in 0..s_vec.len() - 1 {
        if s_vec[i] == s_vec[i + 1] {
            count += 1;
        } else {
            max_count = max_count.max(count);
            count = 1;
        }
    }

    return max_count;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = max_power("leetcode".to_string());
        assert_eq!(ret, 2);
        let ret = max_power("abbcccddddeeeeedcba".to_string());
        assert_eq!(ret, 5);
    }
}