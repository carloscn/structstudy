
fn sum_number(v:i32) -> i32
{
    let mut k:i32 = v;
    let mut ret:i32 = 0;

    while k != 0 {
        ret += k % 10;
        k /= 10;
    }

    return ret;
}

pub fn get_lucky(s: &str, k: i32) -> i32
{
    if s.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;
    let s_v:Vec<char> = s.chars().collect();
    let mut z:i32 = 1;

    for i in 0..s_v.len() {
        let a = (s_v[s_v.len() - 1 - i] as u8 - 'a' as u8 + 1) as i32;
        ret += a * z;
        z *= 10;
    }

    for i in 0..k {
        ret = sum_number(ret);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = get_lucky("iiii", 1);
        assert_eq!(ret, 36);

        let ret = get_lucky("leetcode", 2);
        assert_eq!(ret, 6);

        let ret = get_lucky("zbax", 2);
        assert_eq!(ret, 8);
    }
}