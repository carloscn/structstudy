
fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String>
{
    let mut ret_vec:Vec<String> = vec![];
    let mut s1_vec:Vec<String> = s1.split(" ")
                                   .map(|x| x.to_string())
                                   .collect();

    let mut s1_vec_clone = s1_vec.clone();
    let mut s2_vec:Vec<String> = s2.split(" ")
                                   .map(|x| x.to_string())
                                   .collect();

    s1_vec.retain(|x| !s2_vec.contains(x));
    s2_vec.retain(|x| !s1_vec_clone.contains(x));

    ret_vec.append(&mut s1_vec);
    ret_vec.append(&mut s2_vec);

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    // chatGPT provides test cases
    fn test_demo() {
        let s1 = "this apple is sweet".to_string();
        let s2 = "this apple is sour".to_string();
        let ret = uncommon_from_sentences(s1, s2);
        assert_eq!(ret, vec!["sweet".to_string(), "sour".to_string()]);
    }

    #[test]
    fn test_uncommon_from_sentences() {
        let ret:Vec<String> = vec![];
        // Test case 1: Both sentences have no words in common
        assert_eq!(
            uncommon_from_sentences(
                String::from("apple banana"),
                String::from("orange peach")
            ),
            vec![
                String::from("apple"),
                String::from("banana"),
                String::from("orange"),
                String::from("peach")
            ]
        );

        // Test case 2: Both sentences have some words in common
        assert_eq!(
            uncommon_from_sentences(
                String::from("apple banana"),
                String::from("banana orange")
            ),
            vec![
                String::from("apple"),
                String::from("orange")
            ]
        );

        // Test case 3: Both sentences have all words in common
        assert_eq!(
            uncommon_from_sentences(
                String::from("apple banana"),
                String::from("apple banana")
            ),
            ret
        );

        // Test case 4: One of the sentences is empty
        assert_eq!(
            uncommon_from_sentences(
                String::from("apple banana"),
                String::from("d")
            ),
            vec![
                String::from("apple"),
                String::from("banana"),
                String::from("d")
            ]
        );
        let ret:Vec<String> = vec![];
        // Test case 5: Both sentences are empty
        assert_eq!(
            uncommon_from_sentences(
                String::from(""),
                String::from("")
            ),
            ret
        );
    }
}