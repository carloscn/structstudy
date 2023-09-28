
pub fn largest_good_integer(num: &str) -> String
{
    let mut ret:String = String::new();
    if num.is_empty() {
        return ret;
    }

    let mut max_val:u8 = u8::MIN;
    let num_vec:Vec<char> = num.chars().collect();
    for i in 0..num_vec.len() - 2 {
        if (num_vec[i] == num_vec[i + 1]) &&
           (num_vec[i] == num_vec[i + 2]) {
            max_val = (num_vec[i] as u8).max(max_val);
        }
    }

    if max_val != u8::MIN {
        for _i in 0..3 {
            ret.push(max_val as char);
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = largest_good_integer("6777133339");
        assert_eq!(ret, "777".to_string());
        let ret = largest_good_integer("2300019");
        assert_eq!(ret, "000".to_string());
        let ret = largest_good_integer("42352338");
        assert_eq!(ret, "".to_string());
    }
}