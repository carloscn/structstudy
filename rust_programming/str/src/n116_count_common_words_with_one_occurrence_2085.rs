
fn delete_dup_elements(vec:&mut Vec<&str>)
{
    let mut i = 0;
    while i < vec.len() {
        let current_item = &vec[i].clone();
        if vec.iter().filter(|&&item| item == *current_item).count() > 1 {
            vec.retain(|&item| item != *current_item);
        } else {
            i += 1;
        }
    }
}

pub fn count_words(words1: Vec<&str>, words2: Vec<&str>) -> i32
{
    let mut ret:i32 = 0;

    if words1.len() < 1 || words2.len() < 1 {
        return ret;
    }

    let mut wp1 = words1.clone();
    let mut wp2 = words2.clone();

    delete_dup_elements(&mut wp1);
    delete_dup_elements(&mut wp2);

    for e in &wp1 {
        for k in &wp2 {
            if *e == *k {
                ret += 1;
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = count_words(vec!["leetcode","is","amazing","as","is"],
                            vec!["amazing","leetcode","is"]);
        assert_eq!(ret, 2);
        let ret = count_words(vec!["b","bb","bbb"],
                            vec!["a","aa","aaa"]);
        assert_eq!(ret, 0);
        let ret = count_words(vec!["a","ab"],
                            vec!["a","a","a","ab"]);
        assert_eq!(ret, 1);
    }
}