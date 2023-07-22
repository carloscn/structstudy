
pub fn check_ones_segment(s: &str) -> bool
{
    return s.contains("11");
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = check_ones_segment("1001");
        assert_eq!(ret, false);
        let ret = check_ones_segment("110");
        assert_eq!(ret, true);
    }
}