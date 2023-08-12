
pub fn make_equal(words: Vec<&str>) -> bool
{
    let len = words.len();

    if len < 2 {
        return true;
    }

    let mut rom:Vec<i32> = vec![0; 26];
    for e in words {
        let t_vec:Vec<char> = e.chars().collect();
        for k in t_vec {
            rom[k as usize - 'a' as usize] += 1;
        }
    }

    for e in rom {
        if e as usize % len != 0 {
            return false;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = make_equal(vec!["abc","aabc","bc"]);
        assert_eq!(ret, true);
        let ret = make_equal(vec!["ab","a"]);
        assert_eq!(ret, false);
    }
}