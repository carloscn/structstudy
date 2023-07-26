
pub fn second_highest(s: &str) -> i32
{
    if s.is_empty() {
        return 0;
    }

    let mut s_vec:Vec<char> = s.chars()
                               .filter(|&x| x.is_numeric())
                               .collect();

    s_vec.sort();
    s_vec.dedup();

    if s_vec.len() < 2 {
        return -1;
    } else {
        return ((s_vec[1] as u8) - ('0' as u8)) as i32;
    }
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = second_highest("dfa12321afd");
        assert_eq!(ret, 2);
        let ret = second_highest("abc1111");
        assert_eq!(ret, -1);
    }
}