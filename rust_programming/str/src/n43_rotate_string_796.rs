fn is_rotate_string(str_a:&String, str_b:&String) -> Result<bool, &'static str>
{
    let mut ret:bool = false;
    let mut joint_str:String = String::new();

    if (0 == str_a.len()) ||
       (0 == str_b.len()) {
        return Err("len error!\n");
    }

    joint_str = format!("{}{}", *str_a, *str_a);
    ret = joint_str.contains(str_b);

    return Ok(ret);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_rotate_string_normal() {
        let str_a = "abcde".to_string();
        let str_b = "cdeab".to_string();
        let ret:bool = is_rotate_string(&str_a, &str_b).unwrap_or_else(|err| {
            eprintln!("output err {}", err);
            return false;
        });

        assert_eq!(ret, true);
    }
    #[test]
    fn test_rotate_string_abnormal() {
        let str_a = "abcded".to_string();
        let str_b = "cdeab".to_string();
        let ret:bool = is_rotate_string(&str_a, &str_b).unwrap_or_else(|err| {
            eprintln!("output err {}", err);
            return false;
        });

        assert_eq!(ret, false);
    }
}