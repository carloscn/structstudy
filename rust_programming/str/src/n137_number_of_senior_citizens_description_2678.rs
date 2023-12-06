
pub fn count_seniors(details: Vec<&str>) -> i32
{
    let mut ret:i32 = 0;
    if details.len() < 1 {
        return ret;
    }

    for e in details {
        let age:i32;
        let ev:Vec<char> = e.chars().collect();
        if ev[11].is_digit(10) && ev[12].is_digit(10) {
            age = (ev[11] as i32 - '0' as i32) * 10 + (ev[12] as i32 - '0' as i32);
            if age > 60 {
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
        let ret = count_seniors(vec!["7868190130M7522","5303914400F9211","9273338290F4010"]);
        assert_eq!(ret, 2);

        let ret = count_seniors(vec!["1313579440F2036","2921522980M5644"]);
        assert_eq!(ret, 0);
    }
}