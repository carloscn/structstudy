
fn is_allowed(allowed:&str, word:&str) -> bool
{
    let mut wv:Vec<char> = word.chars().collect();
    let mut e:char;
    wv.sort();

    e = wv[0];
    if wv.len() == 1 {
        return allowed.contains(e);
    }

    for i in 1..word.len() {
        if e == wv[i] {
            continue;
        } else {
            if allowed.contains(wv[i]) {
                e = wv[i];
            } else {
                return false;
            }
        }
    }

    return true;
}

pub fn count_consistent_strings(allowed: &str, words: Vec<&str>) -> i32
{
    if allowed.len() < 1 || words.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;
    for e in words {
        if is_allowed(&allowed, e) {
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
        let allowed = "ab";
        let words = vec!["ad","bd","aaab","baa","badab"];
        let ret = count_consistent_strings(allowed, words);
        assert_eq!(ret, 2);

        let allowed = "abc";
        let words = vec!["a","b","c","ab","ac","bc","abc"];
        let ret = count_consistent_strings(allowed, words);
        assert_eq!(ret, 7);

        let allowed = "cad";
        let words = vec!["cc","acd","b","ba","bac","bad","ac","d"];
        let ret = count_consistent_strings(allowed, words);
        assert_eq!(ret, 4);
    }
}