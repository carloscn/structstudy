
fn is_vowels(ch:char) -> bool
{
    if (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U')||
       (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') {
        return true;
    } else {
        return false;
    }
}

pub fn halves_are_alike(s: &str) -> bool
{
    if s.len() < 1 || s.len() & 1 == 1 {
        return false;
    }

    let s_vec:Vec<char> = s.chars().collect();
    let mut l_count:usize = 0;
    let mut r_count:usize = 0;

    for i in 0..s_vec.len() / 2 {
        if is_vowels(s_vec[i]) {
            l_count += 1;
        }
        if is_vowels(s_vec[i + s_vec.len() / 2]) {
            r_count += 1;
        }
    }

    return l_count == r_count;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = halves_are_alike("book");
        assert_eq!(ret, true);
        let ret = halves_are_alike("textbook");
        assert_eq!(ret, false);
    }
}