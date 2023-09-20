
fn is_same_pref(in_str:&str, pref: &str) -> bool
{
    let in_pref = in_str.get(0..pref.len());

    match (in_pref, pref) {
        (Some(in_pref), pref) => in_pref == pref,
        _ => false,
    }
}

pub fn prefix_count(words: Vec<&str>, pref: &str) -> i32
{
    let mut ret:i32 = 0;

    if words.len() < 1 || pref.len() < 1 {
        return ret;
    }

    for e in words {
        if is_same_pref(e, pref) {
            ret += 1;
        }

    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = prefix_count(vec!["pay","attention","practice","attend"], "at");
        assert_eq!(ret, 2);
        let ret = prefix_count(vec!["leetcode","win","loops","success"], "code");
        assert_eq!(ret, 0);
    }
}