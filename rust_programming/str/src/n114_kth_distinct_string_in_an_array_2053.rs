
pub fn kth_distinct(arr: Vec<&str>, k: i32) -> String
{
    let mut ret:String = String::new();

    if arr.len() < 1 || k < 1 {
        return ret;
    }

    let mut arr_vec:Vec<&str> = arr.clone();
    let mut fin_vec:Vec<&str> = vec![];
    let mut i:usize = 0;

    arr_vec.sort();
    while i < arr_vec.len() {
        if fin_vec.is_empty() || fin_vec[fin_vec.len() - 1] != arr_vec[i] {
            fin_vec.push(arr_vec[i]);
        } else {
            fin_vec.pop();
        }
        i += 1;
    }

    if (k as usize) <= fin_vec.len() {
        ret = fin_vec[k as usize - 1].to_string();
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = kth_distinct(vec!["d","b","c","b","c","a"], 2);
        assert_eq!(ret, "d".to_string());
        let ret = kth_distinct(vec!["aaa","aa","a"], 1);
        assert_eq!(ret, "a".to_string());
        let ret = kth_distinct(vec!["a","b","a"], 3);
        assert_eq!(ret, "".to_string());
    }
}