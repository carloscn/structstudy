use std::string;


fn string_same(a:&str, b:&str) -> bool
{
    let mut a_vec:Vec<char> = a.chars().collect();
    let mut b_vec:Vec<char> = b.chars().collect();

    a_vec.sort();
    b_vec.sort();

    a_vec.dedup();
    b_vec.dedup();

    return a_vec == b_vec;
}

pub fn similar_pairs(words: Vec<&str>) -> i32
{
    let mut ret:i32 = 0;
    if words.len() < 1 {
        return ret;
    }

    let mut max_count:i32 = i32::MIN;
    for i in 0..words.len() {
        let mut count:i32 = 0;
        for j in 0..words.len() {
            if j != i && string_same(words[i], words[j]) {
                count += 1;
            }
        }
        max_count = max_count.max(count);
    }

    if max_count != 0 {
        ret += 1;
    }
    ret += max_count;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = similar_pairs(vec!["aba","aabb","abcd","bac","aabc"]);
        assert_eq!(ret, 2);
        let ret = similar_pairs(vec!["aabb","ab","ba"]);
        assert_eq!(ret, 3);
        let ret = similar_pairs(vec!["nba","cba","dba"]);
        assert_eq!(ret, 0);
    }
}