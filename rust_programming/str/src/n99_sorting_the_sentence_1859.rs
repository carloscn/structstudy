use std::ops::Add;

pub fn sort_sentence(s: &str) -> String
{
    if s.len() == 0 {
        return s.to_string();
    }

    let mut s_vec:Vec<(char, String)> = vec![];
    for e in s.split(" ") {
        let c:char;
        let st:String;
        let sv:Vec<char> = e.chars().collect();
        c = sv[sv.len() - 1];
        st = sv.iter().filter(|x| x.is_alphabetic()).collect();
        s_vec.push((c, st));
    }

    s_vec.sort();

    let mut ret:String = String::new();

    for e in s_vec {
        ret += &e.1;
        ret += " ";
    }

    ret.remove(ret.len() - 1);

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = sort_sentence("is2 sentence4 This1 a3");
        assert_eq!(ret, "This is a sentence");
        let ret = sort_sentence("Myself2 Me1 I4 and3");
        assert_eq!(ret, "Me Myself and I");
    }
}