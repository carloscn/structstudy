
pub fn freq_alphabets(s: String) -> String
{
    let mut ret:String = String::new();
    let mut s_vec:Vec<char> = vec![];
    let mut char_vec:Vec<char> = vec![];

    let dup:Vec<char> = s.chars().into_iter().collect();

    for i in 'a'..'z' {
        char_vec.push(i);
    }
    char_vec.push('z');

    let mut i:usize = 0;
    while i < dup.len() {
        let mut num;
        if dup[dup.len() - i - 1] != '#' {
            num = (dup[dup.len() - i - 1] as u8 - '0' as u8) as usize;
            i += 1;
        } else {
            num = (dup[dup.len() - i - 3] as u8 - '0' as u8) as usize * 10;
            num += (dup[dup.len() - i - 2] as u8 - '0' as u8) as usize;
            i += 3;
        }
        s_vec.insert(0, char_vec[num - 1]);
    }

    let s_str:String = s_vec.into_iter().collect();
    ret.push_str(&s_str);

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let mut ret = freq_alphabets("10#11#12".to_string());
        assert_eq!(ret, "jkab".to_string());
        let mut ret = freq_alphabets("1326#".to_string());
        assert_eq!(ret, "acz".to_string());
    }
}