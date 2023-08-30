
pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32
{
    if nums.len() < 2 || k == 0 {
        return 0;
    }

    let mut ret:i32 = i32::MAX;
    let sub_array_len:i32 = 1 << nums.len();
    let mut s_v:Vec<i32> = vec![];

    for mask in 0..sub_array_len {
        for i in 0..nums.len() as i32 {
            if (mask & (1 << i)) != 0 {
                s_v.push(nums[i as usize]);
            }
        }
        if s_v.len() == 2 {
            ret = ret.min(i32::abs(s_v[0] - s_v[1]));
        }
        s_v.clear();
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = minimum_difference(vec![9,4,1,7], 2);
        assert_eq!(ret, 2);
        let ret = minimum_difference(vec![90], 1);
        assert_eq!(ret, 0);
    }
}