pub fn di_string_match(s: String) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];
    let mut range:Vec<i32> = vec![];
    let s_v:Vec<char> = s.chars().into_iter().collect();

    if s.len() < 1 {
        return ret;
    }

    for i in 0..(s.len() + 1) {
        range.push(i as i32);
    }

    for e in &s_v {
        if 'I' == *e {
            ret.push(*range.get(0).unwrap());
            range.remove(0);
        } else if 'D' == *e {
            ret.push(range.pop().unwrap());
        }
    }
    ret.push(range[0]);

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    // chatGPT provides test cases
    fn test_demo() {
        let ret = di_string_match("IDID".to_string());
        println!("the ret is {:?}", ret);
    }

    #[test]
    fn test_di_string_match() {
        // Test case 1: simple example
        let s1 = String::from("IDID");
        let expected1 = vec![0, 4, 1, 3, 2];
        assert_eq!(di_string_match(s1), expected1);

        // Test case 2: all I's
        let s2 = String::from("IIII");
        let expected2 = vec![0, 1, 2, 3, 4];
        assert_eq!(di_string_match(s2), expected2);

        // Test case 3: all D's
        let s3 = String::from("DDDD");
        let expected3 = vec![4, 3, 2, 1, 0];
        assert_eq!(di_string_match(s3), expected3);

        // Test case 4: empty input string
        let s4 = String::from("");
        let expected4: Vec<i32> = vec![];
        assert_eq!(di_string_match(s4), expected4);

        // Test case 5: alternating I's and D's
        let s5 = String::from("IDIDIDID");
        let expected5 = vec![0, 8, 1, 7, 2, 6, 3, 5, 4];
        assert_eq!(di_string_match(s5), expected5);

        // Test case 6: one character input string
        let s6 = String::from("I");
        let expected6 = vec![0, 1];
        assert_eq!(di_string_match(s6), expected6);

        // Test case 7: one character input string
        let s7 = String::from("D");
        let expected7 = vec![1, 0];
        assert_eq!(di_string_match(s7), expected7);
    }
}