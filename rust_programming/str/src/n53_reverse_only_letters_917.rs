
//   "Test1ng-Leet=code-Q!"
//   "Qedo1ct-eeLg=ntse-T!"

//s1:"Test1ng-Leet=code-Q!"
//s2:"Qest1ng-Leet=code-T!"
//s3:"Qest1ng-Leet=code-T!"
//s4:"Qedt1ng-Leet=cose-T!"
//s5:"Qedo1ng-Leet=ctse-T!"

pub fn reverse_only_letters(s: String) -> String
{
    let mut ret_str:String = String::new();
    let mut left_index:usize = 0;
    let mut right_index:usize = s.len();
    let mut ret_chars:Vec<char> = s.chars().collect();

    if right_index < 1 {
        return ret_str;
    }

    right_index -= 1;
    while left_index < right_index {
        while !ret_chars[left_index].is_alphabetic() &&
              left_index < right_index {
            left_index += 1;
        }
        while !ret_chars[right_index].is_alphabetic() &&
            left_index < right_index {
            right_index -= 1;
        }

        if left_index < right_index {
            ret_chars.swap(left_index, right_index);
            left_index += 1;
            right_index -= 1;
        }
    }

    let s:String = ret_chars.into_iter().collect();
    ret_str.push_str(&s);

    return ret_str;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    // chatGPT provides test cases
    fn test_demo() {
        let str:String = String::from("Test1ng-Leet=code-Q!");
        let ret = reverse_only_letters(str);
        assert_eq!(ret, "Qedo1ct-eeLg=ntse-T!".to_string())
    }

    #[test]
    fn test_reverse_only_letters() {
        assert_eq!(reverse_only_letters("".to_string()), "".to_string());
        assert_eq!(reverse_only_letters("abc123".to_string()), "cba123".to_string());
        assert_eq!(reverse_only_letters("a-bC-dEf-ghIj".to_string()), "j-Ih-gfE-dCba".to_string());
        assert_eq!(reverse_only_letters("Test1ng-Leet=code-Q!".to_string()), "Qedo1ct-eeLg=ntse-T!".to_string());
    }
}