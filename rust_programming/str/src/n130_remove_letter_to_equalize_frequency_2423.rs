use std::collections::HashSet;

fn has_repeat(input:&Vec<char>) -> bool
{
    let mut char_set:HashSet<char> = std::collections::HashSet::new();
    for c in input {
        if !char_set.insert(*c) {
            return true;
        }
    }

    return false;
}

pub fn equal_frequency(word: &str) -> bool
{
    if word.is_empty() {
        return false;
    }

    let mut word_vec:Vec<char> = word.chars().collect();
    for i in 0..word_vec.len() {
        let removed_char: char = word_vec.remove(i);
        if !has_repeat(&word_vec) {
            return true;
        }
        word_vec.insert(i, removed_char);
    }

    return false;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = equal_frequency("abcc");
        assert_eq!(ret, true);

        let ret = equal_frequency("aazz");
        assert_eq!(ret, false);
    }
}