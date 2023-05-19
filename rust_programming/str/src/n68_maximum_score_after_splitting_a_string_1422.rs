
fn count_0(v:&Vec<char>, index:usize) -> usize
{
    let mut ret:usize = 0;

    for i in 0..(index + 1) {
        if v[i] == '0' {
            ret += 1;
        }
    }

    return ret;
}

pub fn max_score(s: String) -> i32
{
    if s.is_empty() {
        return 0;
    }

    let mut count_1:usize = 0;
    let s_vec:Vec<char> = s.chars().collect();

    for e in &s_vec {
        if *e == '1' {
            count_1 += 1;
        }
    }
    let mut max_count:usize = 0;
    for i in 0..s.len() {
        let l_count_0:usize = count_0(&s_vec, i);
        let r_count_1:usize = count_1 - (i + 1 - l_count_0);

        if max_count < l_count_0 + r_count_1 {
            max_count = l_count_0 + r_count_1;
        }
    }

    return max_count as i32;
}

#[cfg(test)]
mod tests {
    use std::string;

    use super::*;

    #[test]
    fn demo() {
        let ret = max_score("011101".to_string());
        assert_eq!(ret, 5);
        let ret = max_score("1111".to_string());
        assert_eq!(ret, 3);
    }
}