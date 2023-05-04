

pub fn maximum69_number(num: i32) -> i32
{
    let mut i:usize = 0;
    let mut dup_num:String = num.to_string();
    let mut dup_vec:Vec<char> = dup_num.chars().collect();

    while i < dup_num.len() {
        if dup_vec[i] == '6' {
            dup_vec[i] = '9';
            break;
        }
        i += 1;
    }

    dup_num = dup_vec.into_iter().collect();

    return dup_num.parse::<i32>().unwrap();
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashSet;

    #[test]
    fn test_demo() {
        let mut ret = maximum69_number(9669);
        assert_eq!(ret, 9969);
        ret = maximum69_number(9996);
        assert_eq!(ret, 9999);
        ret = maximum69_number(9999);
        assert_eq!(ret, 9999);
    }
}