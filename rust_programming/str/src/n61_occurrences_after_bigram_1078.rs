
pub fn find_ocurrences(text: String, first: String, second: String) -> Vec<String>
{
    let text_vec:Vec<String> = text.split(" ")
                                   .into_iter()
                                   .map(|x| x.to_string())
                                   .collect();
    if text_vec.len() < 3 {
        return vec![];
    }

    let mut ret_vec:Vec<String> = vec![];
    let mut i:usize = 0;

    while i < text_vec.len() - 2 {
        if first == text_vec[i] {
            if second == text_vec[i + 1] {
                ret_vec.push(text_vec[i + 2].clone());
            }
        }
        i += 1;
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn demo() {
        let text = "alice is a good girl she is a good student".to_string();
        let first = "a".to_string();
        let second = "good".to_string();

        let ret = find_ocurrences(text, first, second);
        assert_eq!(ret, vec!["girl".to_string(), "student".to_string()]);
    }
    #[test]
    fn test_find_ocurrences() {
        // Test case 1
        let text = String::from("alice is a good girl she is a good student");
        let first = String::from("a");
        let second = String::from("good");
        let result = find_ocurrences(text, first, second);
        let expected = vec![String::from("girl"), String::from("student")];
        assert_eq!(result, expected);

        // Test case 2
        let text = String::from("we will we will rock you");
        let first = String::from("we");
        let second = String::from("will");
        let result = find_ocurrences(text, first, second);
        let expected = vec![String::from("we"), String::from("rock")];
        assert_eq!(result, expected);

        // Test case 3
        let text = String::from("this is a test for the function");
        let first = String::from("test");
        let second = String::from("for");
        let result = find_ocurrences(text, first, second);
        let expected = vec![String::from("the")];
        assert_eq!(result, expected);
    }
}