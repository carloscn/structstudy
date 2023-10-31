
pub fn maximum_value(strs: Vec<&str>) -> i32
{
    let mut ret:i32 = 0;
    if strs.len() < 1 {
        return ret;
    }

    let mut max_len:usize = usize::MIN;

    for e in strs {
        let in_vec:Vec<char> = e.chars().collect();
        if in_vec.iter().any(|x| x.is_alphabetic()) {
            max_len = in_vec.len().max(max_len);
        } else {
            match e.parse::<usize>() {
                Ok(parsed) => {
                    max_len = parsed.max(max_len);
                },
                Err(_) => {
                    ret = -1;
                    return ret;
                }
            }
        }
    }

    ret = max_len as i32;

    return ret;
}

#[test]
fn demo() {
    let ret = maximum_value(vec!["alic3","bob","3","4","00000"]);
    assert_eq!(ret, 5);

    let ret = maximum_value(vec!["1","01","001","0001"]);
    assert_eq!(ret, 1);
}