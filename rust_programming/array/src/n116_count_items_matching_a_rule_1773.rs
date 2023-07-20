
pub fn count_matches(items: Vec<Vec<&str>>, rule_key: &str, rule_value: &str) -> i32
{
    if items.is_empty() || rule_key.is_empty() || rule_value.is_empty() {
        return 0;
    }

    let index:usize;

    if rule_key == "type" {
        index = 0;
    } else if rule_key == "color" {
        index = 1;
    } else if rule_key == "name" {
        index = 2;
    } else {
        return 0;
    }
    let mut ret:i32 = 0;

    for e in &items {
        if (*e)[index] == rule_value {
            ret += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = count_matches(
                vec![
                        vec!["phone","blue","pixel"],
                        vec!["computer","silver","lenovo"],
                        vec!["phone","gold","iphone"]
                       ],
                        "color",
                        "silver");
        assert_eq!(ret, 1);

        let ret = count_matches(
                vec![vec!["phone","blue","pixel"],
                            vec!["computer","silver","phone"],
                            vec!["phone","gold","iphone"]
                    ],
                    "type",
                    "phone");
        assert_eq!(ret, 2);
    }
}