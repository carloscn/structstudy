
fn position_of_large_groups(s: &String) -> Vec<Vec<i32>>
{
    let mut ret_vec:Vec<Vec<i32>> = vec![];
    let in_chars:Vec<u8> = (*s).chars().map(|x| x as u8).collect();
    let in_len:usize = s.len();
    let mut i:usize = 0;
    let mut pos_t:Vec<i32> = vec![];

    while i < in_len - 1 {
        if in_chars[i] == in_chars[i + 1] {
            let len = pos_t.len();
            if len < 2 {
                pos_t.push(i as i32);
            } else {
                pos_t[len - 1] = i as i32;
            }
        } else {
            if pos_t.is_empty() == false {
                let len = pos_t.len();
                if len < 2 {
                    pos_t.clear();
                    continue;
                }
                pos_t[len - 1] += 1;
                ret_vec.push(pos_t.clone());
                pos_t.clear();
            }
        }
        i += 1;
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    //            "0123456789abcdef"
    // Input: s = "abcdddeeeeaabbbcd"
    // Output: [[3,5],[6,9],[12,14]]
    // Explanation: The large groups are "ddd", "eeee", and "bbb".
    pub fn test_position_of_larget_groups1() {
        let ret = position_of_large_groups(&"abcdddeeeeaabbbcd".to_string());
        assert_eq!(ret, vec![vec![3_i32, 5_i32],vec![6i32, 9i32],vec![12i32, 14i32]]);
    }

    #[test]
    //            "0123456789abcdef"
    // Input: s = "abbxxxxzzy"
    // Output: [[3,6]]
    // Explanation: "xxxx" is the only large group with start index 3 and end index 6.
    pub fn test_position_of_larget_groups2() {
        let ret = position_of_large_groups(&"abbxxxxzzy".to_string());
        assert_eq!(ret, vec![vec![3_i32, 6_i32]]);
    }
}