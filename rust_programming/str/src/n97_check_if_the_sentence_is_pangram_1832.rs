
pub fn check_if_pangram(sentence: &str) -> bool
{
    if sentence.len() < 26 {
        return false;
    }

    let mut s:Vec<char> = sentence.chars()
                                  .filter(|x| x.is_alphabetic())
                                  .collect();
    if s.len() < 26 {
        return false;
    }

    s.dedup();

    if s.len() < 26 {
        return false;
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = check_if_pangram("thequickbrownfoxjumpsoverthelazydog");
        assert_eq!(ret, true);
        let ret = check_if_pangram("dddddddddddddddddddddddddddddddddddddddd");
        assert_eq!(ret, false);
        let ret = check_if_pangram("leetcode");
        assert_eq!(ret, false);
    }
}