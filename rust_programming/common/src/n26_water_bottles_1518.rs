
pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32
{
    if num_bottles < 1 || num_exchange < 1 {
        return 0;
    }

    let mut ret:i32 = num_bottles;
    let mut count_empty:i32 = num_bottles;
    let mut count_full:i32;

    while count_empty >= num_exchange {
        let t = count_empty;
        count_full = t / num_exchange;
        count_empty = t % num_exchange + count_full;
        ret += count_full;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_demo() {
        let ret = num_water_bottles(9, 3);
        assert_eq!(ret, 13);

        let ret = num_water_bottles(15, 4);
        assert_eq!(ret, 19);
    }
}