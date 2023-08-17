
pub fn can_be_typed_words(text: &str, broken_letters: &str) -> i32
{
    if text.is_empty() || broken_letters.is_empty() {
        return 0;
    }

    let mut ret:i32 = 0;
    let bro_vec:Vec<char> = broken_letters.chars().collect();

    for e in text.split(" ") {
        let mut flag:i32 = 1;
        for c in &bro_vec {
            if e.contains(*c) {
                flag = 0;
                break;
            }
        }
        ret += flag;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = can_be_typed_words("hello world", "ad");
        assert_eq!(ret, 1);
        let ret = can_be_typed_words("leet code", "lt");
        assert_eq!(ret, 1);
        let ret = can_be_typed_words("leet code", "e");
        assert_eq!(ret, 0);
    }
}