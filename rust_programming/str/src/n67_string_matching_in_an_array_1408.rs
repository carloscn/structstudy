
pub fn string_matching(words: Vec<String>) -> Vec<String>
{
    if words.is_empty() {
        return words;
    }

    let mut ret:Vec<String> = vec![];

    for i in 0..words.len() {
        for j in 0..words.len() {
            if i != j && words[j].contains(&words[i]) {
                ret.push(words[i].clone());
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::string;

    use super::*;

    #[test]
    fn demo() {
        let ret = string_matching(vec!["mass".to_string(),"as".to_string(),"hero".to_string(),"superhero".to_string()]);
        assert_eq!(ret, vec!["as".to_string(),"hero".to_string()]);
        let ret = string_matching(vec!["leetcode".to_string(),"et".to_string(),"code".to_string()]);
        assert_eq!(ret, vec!["et".to_string(),"code".to_string()]);
        let ret = string_matching(vec!["blue".to_string(),"green".to_string(),"bu".to_string()]);
        assert_eq!(ret, Vec::<String>::new());
    }
}