
pub fn square_is_white(coordinates: &str) -> bool
{
    if coordinates.len() < 1 {
        return false;
    }

    let rcv:Vec<char> = coordinates.chars().collect();

    if rcv[0] as u8 + 1 & 0x1 == 1 ||
       rcv[1] as u8 + 1 & 0x1 == 1 {
        return true;
    }

    return false;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = square_is_white("a1");
        assert_eq!(ret, false);
        let ret = square_is_white("h3");
        assert_eq!(ret, true);
        let ret = square_is_white("c7");
        assert_eq!(ret, false);
    }
}