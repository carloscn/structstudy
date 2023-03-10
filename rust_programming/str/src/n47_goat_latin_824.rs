fn is_vowel_str(in_str:&str) -> bool
{
    if (*in_str).starts_with("a") ||
       (*in_str).starts_with("e") ||
       (*in_str).starts_with("i") ||
       (*in_str).starts_with("o") ||
       (*in_str).starts_with("u") ||
       (*in_str).starts_with("A") ||
       (*in_str).starts_with("E") ||
       (*in_str).starts_with("I") ||
       (*in_str).starts_with("O") ||
       (*in_str).starts_with("U") {
        return true;
    }

    return false;
}

fn rewrite(in_str:&str) -> String
{
    let mut ret_str:String = String::new();

    if is_vowel_str(in_str) {
        ret_str.push_str(in_str);
        ret_str.push_str("ma");
    } else {
        ret_str.push_str(&in_str[1..in_str.len()]);
        ret_str.push_str(&in_str[0..1]);
        ret_str.push_str("ma");
    }

    return ret_str;
}

fn goat_latin(in_str:&String) -> String
{
    let mut ret_str:String = String::new();
    let mut in_str_list:Vec<&str> = (*in_str).split(" ").collect();
    let mut i:usize = 1;
    let mut j:usize = 0;

    for e in in_str_list {
        let ret = rewrite(e);
        ret_str.push_str(&ret);
        while j < i {
            ret_str.push('a');
            j += 1;
        }
        ret_str.push(' ');
        i += 1;
        j = 0;
    }

    ret_str.pop();

    return ret_str;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_goat_latin1() {
        let ret = goat_latin(&"I speak Goat Latin".to_string());
        assert_eq!(ret, "Imaa peaksmaaa oatGmaaaa atinLmaaaaa".to_string());
    }

    #[test]
    pub fn test_goat_latin2() {
        let ret = goat_latin(&"The quick brown fox jumped over the lazy dog".to_string());
        assert_eq!(ret, "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa".to_string());
    }
}