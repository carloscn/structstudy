fn detect_capital(in_str: &str, result : &mut bool) -> i32
{
    let mut ret : i32 = 0;
    let len : usize = in_str.len() as usize;
    let mut c_count : usize = 0;
    let mut l_count : usize = 0;
    let cap;

    *result = false;
    if len == 0 {
        ret = 0;
        return ret;
    }

    let char_v : Vec<char> = in_str.chars().collect();
    cap = char_v[0].clone();
    for i in char_v {
        if utils::num::is_capital(i) {
            c_count = c_count + 1;
        } else if utils::num::is_capital(i) {
            l_count = l_count + 1;
        }
    }

    if (c_count == len) && (l_count == 0) {
        *result = true;
        return ret;
    }

    if (c_count == 0) && (l_count == len) {
        *result = true;
        return ret;
    }

    if (c_count == 1) &&
       (l_count == len - 1) &&
       (utils::num::is_capital(cap)) {
        *result = true;
        return ret;
    }

    return 0;
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_detect_capital() {
        let mut in_str = "hello".to_string();
        let mut result : bool = true;
        let mut ret;

        ret = detect_capital(&in_str, &mut result);
        if ret != 0 {
            println!("failed");
        }
        println!("result {} is {}", in_str, result);

        in_str = "Hello".to_string();
        ret = detect_capital(&in_str, &mut result);
        if ret != 0 {
            println!("failed");
        }
        println!("result {} is {}", in_str, result);

        in_str = "hEllo".to_string();
        ret = detect_capital(&in_str, &mut result);
        if ret != 0 {
            println!("failed");
        }
        println!("result {} is {}", in_str, result);

        in_str = "HELLO".to_string();
        ret = detect_capital(&in_str, &mut result);
        if ret != 0 {
            println!("failed");
        }
        println!("result {} is {}", in_str, result);

        in_str = "hellO".to_string();
        ret = detect_capital(&in_str, &mut result);
        if ret != 0 {
            println!("failed");
        }
        println!("result {} is {}", in_str, result);
    }
}