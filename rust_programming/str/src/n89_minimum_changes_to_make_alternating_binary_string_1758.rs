
pub fn min_operations(s: &str) -> i32
{
    let mut ret:i32 = 0;

    if s.len() < 1 {
        return ret;
    }

    let s_vec:Vec<char> = s.chars().collect();

    let mut i_count:i32 = 0;
    let mut u_count:i32 = 0;

    for i in 0..s.len() {
        if s_vec[i] == ((i & 0x1) as u8 + '0' as u8) as char {
            i_count += 1;
        } else {
            u_count += 1;
        }
    }

    ret = i_count.min(u_count);

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = min_operations("0100");
        assert_eq!(ret, 1);
        let ret = min_operations("10");
        assert_eq!(ret, 0);
        let ret = min_operations("1111");
        assert_eq!(ret, 2);
    }
}