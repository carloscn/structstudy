use std::vec;


pub fn are_occurrences_equal(s: &str) -> bool
{
    if s.len() < 1 {
        return false;
    }

    let mut s_vec:Vec<char> = s.chars().collect();
    let mut k_vec:Vec<char> = vec![];
    let mut count:i32;
    let mut last_count:i32 = 0;
    let mut first = true;
    s_vec.sort();
    s_vec.push(' ');

    for i in 0..s_vec.len() {
        if k_vec.is_empty() {
            k_vec.push(s_vec[i]);
            continue;
        } else {
            if k_vec[k_vec.len() - 1] != s_vec[i] {
                count = k_vec.len() as i32;
                if last_count != count {
                    if first == false {
                        return false;
                    }
                }
                last_count = count;
                first = false;
                k_vec.clear();

            }
            k_vec.push(s_vec[i]);
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let mut ret = are_occurrences_equal("abacbc");
        assert_eq!(ret, true);
        let mut ret = are_occurrences_equal("aaabb");
        assert_eq!(ret, false);
    }
}