
pub fn closet_target(words: Vec<&str>, target: &str, start_index: i32) -> i32
{
    let mut ret:i32 = 0;
    if words.is_empty() || target.is_empty() {
        return ret;
    }

    let mut i:i32 = 0;
    while i < words.len() as i32 {
        if words[(i + start_index) as usize % words.len() as usize] == target {
            break;
        }
        i += 1;
    }

    if i as usize == words.len() {
        return -1;
    }
    ret = i as i32;

    i = 0;
    while i < words.len() as i32{
        let index;
        if start_index - i >= 0 {
            index = start_index - i;
        } else {
            index = start_index - i + words.len() as i32;
        }
        if words[index as usize] == target {
            break;
        }
        i += 1;
    }
    ret = i.min(ret);

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = closet_target(vec!["hello","i","am","leetcode","hello"], "hello", 1);
        assert_eq!(ret, 1);

        let ret = closet_target(vec!["a","b","leetcode"], "leetcode", 0);
        assert_eq!(ret, 1);

        let ret = closet_target(vec!["a","b","leetcode"], "ate", 0);
        assert_eq!(ret, -1);
    }
}