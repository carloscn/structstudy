
fn to_min(times:&str) -> i32
{
    let mut ret:i32 = 0;

    let s:Vec<char> = times.chars().collect();

    ret = s[0] as i32 * 600 + s[1] as i32 * 60 +
          s[3] as i32 * 10 + s[4] as i32;

    return ret;
}

pub fn convert_time(current: &str, correct: &str) -> i32
{
    let mut ret:i32 = 0;
    if current.is_empty() || correct.is_empty() {
        return ret;
    }

    ret = to_min(correct) - to_min(current);
    ret = ret / 60 + ret % 60 / 15 + ret % 15 / 5 + ret % 5;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = convert_time("02:30", "04:35");
        assert_eq!(ret, 3);
        let ret = convert_time("11:00", "11:01");
        assert_eq!(ret, 1);
    }
}