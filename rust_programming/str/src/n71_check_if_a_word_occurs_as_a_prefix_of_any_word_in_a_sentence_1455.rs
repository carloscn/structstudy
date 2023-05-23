
fn is_str_prefix(instr:&String, pattern:&String) -> bool
{
    let instr_vec:Vec<char> = instr.chars().collect();
    let pattern_vec:Vec<char> = pattern.chars().collect();

    for i in 0..pattern.len() {
        if instr_vec[i] != pattern_vec[i] {
            return false;
        }
    }

    return true;
}

pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32
{
    if sentence.is_empty() ||
       search_word.is_empty() {
        return -1_i32;
    }

    let mut ret:i32 = 0;
    let str_vec:Vec<String> = sentence.split(" ")
                                      .into_iter()
                                      .map(|x| x.to_string())
                                      .collect();
    for str in &str_vec {
        if is_str_prefix(str, &search_word) {
            return ret + 1;
        }
        ret += 1;
    }

    if ret == str_vec.len() as i32 {
        ret = -1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = is_prefix_of_word("i love eating burger".to_string(), "burg".to_string());
        assert_eq!(ret, 4);
        let ret = is_prefix_of_word("this problem is an easy problem".to_string(), "pro".to_string());
        assert_eq!(ret, 2);
        let ret = is_prefix_of_word("i am tired".to_string(), "you".to_string());
        assert_eq!(ret, -1);
    }
}