
pub fn restore_string(s: String, indices: Vec<i32>) -> String
{
    if s.is_empty() ||
       indices.is_empty() ||
       s.len() != indices.len() {
        return String::new();
    }

    let ret_str:String;
    let mut s_vec:Vec<char> = s.chars().collect();
    let mut ind_dup = indices.clone();

    for j in 0..s_vec.len() {
        for i in 0..s_vec.len() - j - 1 {
            if ind_dup[i] > ind_dup[i + 1] {
                let t = ind_dup[i];
                ind_dup[i] = ind_dup[i + 1];
                ind_dup[i + 1] = t;

                let t = s_vec[i];
                s_vec[i] = s_vec[i + 1];
                s_vec[i + 1] = t;
            }
        }
    }

    ret_str = s_vec.into_iter().collect();

    return ret_str;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = restore_string("codeleet".to_string(), vec![4,5,6,7,0,2,1,3]);
        assert_eq!(ret, "leetcode".to_string());
        let ret = restore_string("abc".to_string(), vec![0,1,2]);
        assert_eq!(ret, "abc".to_string());
    }
}