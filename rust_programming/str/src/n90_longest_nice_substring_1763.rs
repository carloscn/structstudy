
fn is_tall(e1:&char, e2:&char) -> bool
{
    if ((*e1).is_ascii_lowercase() && (*e1).to_ascii_uppercase() == *e2) ||
       ((*e1).is_ascii_uppercase() && (*e1).to_ascii_lowercase() == *e2) {
        return true;
    }

    return false;
}

pub fn longest_nice_substring(s: &str) -> String
{
    if s.len() < 1 {
        return s.to_string();
    }

    let mut s_vec:Vec<char> = s.chars().collect();
    let mut r_vec:Vec<char> = vec![];
    let mut queue:Vec<char> = vec![];

    s_vec.push('\0');

    let mut i:usize = 0;
    while i < s_vec.len() - 1 {
        if is_tall(&s_vec[i], &s_vec[i + 1]) {
            queue.push(s_vec[i]);
        } else {
            if queue.is_empty() {
                i += 1;
                continue;
            }

            if is_tall(&queue[queue.len() - 1], &s_vec[i]) {
                queue.push(s_vec[i]);
            }

            if r_vec.len() < queue.len() {
                r_vec = queue.clone();
            }
            queue.clear();
        }
        i += 1;
    }

    return r_vec.into_iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = longest_nice_substring("YazaAay");
        assert_eq!(ret, "aAa".to_string());
        let ret = longest_nice_substring("Bb");
        assert_eq!(ret, "Bb".to_string());
        let ret = longest_nice_substring("c");
        assert_eq!(ret, "".to_string());
        let ret = longest_nice_substring("dDzeE");
        assert_eq!(ret, "dD".to_string());
    }
}