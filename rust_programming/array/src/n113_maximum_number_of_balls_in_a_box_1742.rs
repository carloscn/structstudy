use std::collections::HashMap;

fn pos_sum(val:i32) -> i32
{
    let mut vp:i32 = val;
    let mut ret:i32 = 0;

    while vp != 0 {
        ret += vp % 10;
        vp /= 10;
    }

    return ret;
}

pub fn count_balls(low_limit: i32, high_limit: i32) -> i32
{
    if high_limit < low_limit {
        return 0;
    }

    let mut ret:i32 = i32::MIN;
    let mut box_num:HashMap<i32, i32> = HashMap::new();

    for i in low_limit..high_limit + 1 {
        *box_num.entry(pos_sum(i)).or_default() += 1;
    }

    box_num.iter().fold(i32::MIN, |count, (bx, num)| {
        ret = count.max(*num); ret
    });

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = count_balls(1, 10);
        assert_eq!(ret, 2);
        let ret = count_balls(5, 15);
        assert_eq!(ret, 2);
        let ret = count_balls(19, 28);
        assert_eq!(ret, 2);
    }
}