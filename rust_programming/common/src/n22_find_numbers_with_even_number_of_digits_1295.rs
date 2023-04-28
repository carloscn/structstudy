
fn is_even(e:i32) -> bool
{
    let size_table:Vec<i32> =
        vec![9, 99, 999, 9999, 99999,
             999999, 9999999, 99999999,
             999999999, i32::max_value()];

    let mut count = 0;
    for x in &size_table {
        count += 1;
        if e <= *x {
            break;
        }
    }

    return (count & 0x1) == 0;
}

pub fn find_numbers(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if nums.len() < 1 {
        return ret;
    }

    for e in nums {
        if is_even(e) {
            ret += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let ret = find_numbers(vec![12, 345, 2, 6, 7896]);
        assert_eq!(ret, 2);

    }
}