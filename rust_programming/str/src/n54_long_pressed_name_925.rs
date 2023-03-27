pub fn is_long_pressed_name(name: String, typed: String) -> bool
{
    let mut name_dup:Vec<char> = name.chars().into_iter().collect();
    let mut type_dup:Vec<char> = typed.chars().into_iter().collect();
    let mut last_e = '\0';

    for i in 0..name.len() {
        let name_p = name_dup.pop().unwrap();
        for j in 0..type_dup.len() {
            let name_t = type_dup.pop().unwrap();
            if name_p == name_t {
                last_e = name_t;
                break;
            } else {
                if name_t == last_e {
                    last_e = name_t;
                    continue;
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    // chatGPT provides test cases
    fn test_demo() {
        let name:String = "alex".to_string();
        let typed:String = "aaleex".to_string();
        let ret = is_long_pressed_name(name, typed);
        assert_eq!(ret, true);

        let name:String = "saeed".to_string();
        let typed:String = "ssaaedd".to_string();
        let ret = is_long_pressed_name(name, typed);
        assert_eq!(ret, false);
    }

    #[test]
    fn test_is_long_pressed_name() {
        // Case 1: Both strings are empty
        assert_eq!(is_long_pressed_name(String::from(""), String::from("")), true);

        // Case 2: typed contains all characters in name, in the same order
        assert_eq!(is_long_pressed_name(String::from("alex"), String::from("aaleex")), true);

        // Case 3: typed contains some additional characters that are not in name
        assert_eq!(is_long_pressed_name(String::from("saeed"), String::from("ssaaedd")), false);

        // Case 4: typed contains some characters in a different order than in name
        assert_eq!(is_long_pressed_name(String::from("leelee"), String::from("lleeelee")), true);

        // Case 5: typed contains some characters that are not in name, followed by some that are in name
        assert_eq!(is_long_pressed_name(String::from("laiden"), String::from("laidennn")), true);
    }
}