
pub fn count_asterisks(s: &str) -> i32
{
    let mut ret:i32 = 0;
    if s.len() < 1 {
        return ret;
    }

    let mut i:usize = 0;
    let s_vec:Vec<&str> = s.split('|').into_iter().collect();

    while i < s_vec.len() {
        i += 1;
        if (i & 0x1) == 0 {
            continue;
        }
        let e = s_vec[i - 1];
        ret += e.chars().fold(0, |mut count, x| {
            if x == '*' {
                count += 1;
            }
            count
        });
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = count_asterisks("l|*e*et|c**o|*de|");
        assert_eq!(ret, 2);

        let ret = count_asterisks("iamprogrammer");
        assert_eq!(ret, 0);

        let ret = count_asterisks("yo|uar|e**|b|e***au|tifu|l");
        assert_eq!(ret, 5);
    }
}