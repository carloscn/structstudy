
fn convert_i32(input: &str) -> i32
{
    if input.len() < 1 {
        return -1;
    }

    let mut ret:i32 = 0;
    let mut in_vec:Vec<i32> = input.chars()
                                   .map(|x| (x as u8 - 'a' as u8) as i32)
                                   .collect();

    for i in 0..in_vec.len() {
        ret += in_vec[in_vec.len() - i - 1] * i32::pow(10, i as u32);
    }

    return ret;
}

pub fn is_sum_equal(first_word: &str, second_word: &str, target_word: &str) -> bool
{
    if first_word.is_empty() ||
       second_word.is_empty() ||
       target_word.is_empty() {
        return false;
    }

    let f = convert_i32(first_word);
    if f < 0 {
        return false;
    }
    let s = convert_i32(second_word);
    if s < 0 {
        return false;
    }
    let t = convert_i32(target_word);
    if t < 0 || f + s != t {
        return false;
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = is_sum_equal("acb", "cba", "cdb");
        assert_eq!(ret, true);
        let ret = is_sum_equal("aaa", "a", "aab");
        assert_eq!(ret, false);
        let ret = is_sum_equal("aaa", "a", "aaaa");
        assert_eq!(ret, true);
    }
}