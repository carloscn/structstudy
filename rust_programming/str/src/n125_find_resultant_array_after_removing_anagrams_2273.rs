
fn is_anagram(str1:&str, str2:&str) -> bool
{
    if str1.len() != str2.len() {
        return false;
    }

    let mut chars1 = str1.chars().collect::<Vec<char>>();
    let mut chars2 = str2.chars().collect::<Vec<char>>();

    chars1.sort();
    chars2.sort();

    return chars1 == chars2;
}

pub fn remove_anagrams(words: Vec<&str>) -> Vec<String>
{
    if words.len() < 1 {
        return vec![];
    }

    let mut words_dup: Vec<&str> = words.clone();
    let mut i:usize = 0;

    while i < words_dup.len() - 1 {
        let mut j:usize = i + 1;
        while j < words_dup.len() {
            if is_anagram(words_dup[i], words_dup[j]) {
                words_dup.remove(j);
                j -= 1;
            }
            j += 1;
        }
        i += 1;
    }

    return words_dup.into_iter().map(|x| x.to_string()).collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = remove_anagrams(vec!["abba","baba","bbaa","cd","cd"]);
        assert_eq!(ret, vec!["abba".to_string(),"cd".to_string()]);

        let ret = remove_anagrams(vec!["a","b","c","d","e"]);
        assert_eq!(ret, vec!["a".to_string(),"b".to_string(),"c".to_string(),"d".to_string(),"e".to_string()]);
    }
}