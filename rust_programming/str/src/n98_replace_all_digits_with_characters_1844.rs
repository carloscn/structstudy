
fn shift(c:char, num:i32) -> char
{
    return (c as u8 + num as u8) as char;
}

pub fn replace_digits(s: &str) -> String
{
    if s.len() < 1 {
        return String::new();
    }

    let mut sv:Vec<char> = s.chars().collect();

    for i in 0..sv.len() {
        let c:char;
        if i & 1 == 1 {
            c = shift(sv[i - 1], sv[i] as i32 - 48);
            sv[i] = c;
        }
    }

    return sv.iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = replace_digits("a1c1e1");
        assert_eq!(ret, "abcdef".to_string());
        let ret = replace_digits("a1b2c3d4e");
        assert_eq!(ret, "abbdcfdhe".to_string());
    }
}