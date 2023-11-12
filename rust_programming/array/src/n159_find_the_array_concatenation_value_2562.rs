
fn concate_nums(a:i32, b:i32) -> i32
{
    let concatenated_str = format!("{}{}", a, b);

    if let Ok(result) = concatenated_str.parse::<i32>() {
        result
    } else {
        -1
    }
}

pub fn find_the_array_conc_val(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;
    if nums.len() < 1 {
        return ret;
    }

    let mut i:usize = 0;
    let mut j:usize = nums.len() - 1;

    while i < j {
        let e1 = nums[i];
        let e2 = nums[j];
        let e3 = concate_nums(e1, e2);
        ret += e3;
        i += 1;
        j -= 1;
    }
    if (nums.len() & 0x1) == 1 {
        ret += nums[nums.len() / 2];
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = find_the_array_conc_val(vec![7,52,2,4]);
        assert_eq!(ret, 596);

        let ret = find_the_array_conc_val(vec![5,14,13,8,12]);
        assert_eq!(ret, 673);
    }
}