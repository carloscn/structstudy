
pub fn minimum_moves(s: &str) -> i32
{
    let mut ret:i32 = 0;

    if s.len() < 1 {
        return ret;
    }

    let s_v:Vec<char> = s.chars().collect();
    let mut count:usize = 0;

    for i in 0..s_v.len() {
        if s_v[i] != 'X' {
            count = 0;
            continue;
        } else {
            if count == 0 {
                ret += 1;
            }
            count += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = minimum_moves("XXX");
        assert_eq!(ret, 1);
        let ret = minimum_moves("XXOX");
        assert_eq!(ret, 2);
        let ret = minimum_moves("OOOO");
        assert_eq!(ret, 0);
    }
}