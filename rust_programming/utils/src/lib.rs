
pub fn utils_max(n:u64, m:u64) -> u64 {
    if n > m {
        return n;
    } else {
        return m;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = utils_max(2, 9);
        assert_eq!(result, 9);
    }
}
