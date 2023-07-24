
pub fn are_almost_equal(s1: &str, s2: &str) -> bool
{
    if s1.len() < 1 || s1.len() != s2.len() {
        return true;
    }

    let s1_vec:Vec<char> = s1.chars().collect();
    let s2_vec:Vec<char> = s2.chars().collect();
    let mut d1:char = '\0';
    let mut d2:char = '\0';
    let mut first:bool = true;
    for i in 0..s1_vec.len() {
        if s1_vec[i] != s2_vec[i] && first == true {
            d1 = s1_vec[i];
            d2 = s2_vec[i];
            first = false;
        } else if s1_vec[i] != s2_vec[i] && first == false {
            if d1 != s2_vec[i] && d2 != s1_vec[i] {
                return false;
            }
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = are_almost_equal("bank", "kanb");
        assert_eq!(ret, true);
        let ret = are_almost_equal("attack", "defend");
        assert_eq!(ret, false);
        let ret = are_almost_equal("kelb", "kelb");
        assert_eq!(ret, true);
    }
}