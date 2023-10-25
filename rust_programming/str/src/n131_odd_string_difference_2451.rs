
pub fn odd_string(words: Vec<&str>) -> String
{
    if words.len() < 1 {
        return String::new();
    }

    let mut rom:Vec<(Vec<i32>, String)> = vec![];
    
    for i in 0..words.len() {
        let mut vp:Vec<char> = words[i].chars().collect();
        let mut cv:Vec<i32> = vec![0;2];
        cv[0] = (vp[1] as i8 - vp[0] as i8) as i32;
        cv[1] = (vp[2] as i8 - vp[1] as i8) as i32;
        rom.push(((cv, words[i].to_string())));
    }

    for item in &rom {
        let is_unique = rom.iter().filter(|&x| x.0 == item.0).count() == 1;
        if is_unique {
            return item.clone().1;
        }
    }
    
    return String::new();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = odd_string(vec!["adc","wzy","abc"]);
        assert_eq!(ret, "abc".to_string());

        let ret = odd_string(vec!["aaa","bob","ccc","ddd"]);
        assert_eq!(ret, "bob".to_string());
    }
}