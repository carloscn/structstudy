
pub fn largest_odd_number(num: &str) -> String
{
    if num.len() < 1 {
        return String::new();
    }

    let mut num_vec:Vec<char> = num.chars().collect();

    while num_vec.len() != 0 {
        if num_vec[num_vec.len() - 1] as u8 & 1 == 1 {
            break;
        }
        num_vec.remove(num_vec.len() - 1);
    }

    let ret:String = num_vec.into_iter().collect();

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = largest_odd_number("52");
        assert_eq!(ret, "5".to_string());
        let ret = largest_odd_number("4206");
        assert_eq!(ret, "".to_string());
        let ret = largest_odd_number("35427");
        assert_eq!(ret,"35427".to_string());
    }
}