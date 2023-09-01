
pub fn count_quadruplets(nums: Vec<i32>) -> i32
{
    if nums.len() < 4 {
        return -1;
    }

    let mut ret:i32 = 0;
    let len:usize = 1 << nums.len();

    for mask in 0..len {
        // count '1' bits number
        {
            let mut count:usize = 0;
            let mut t_mask:usize = mask;
            while t_mask != 0 {
                t_mask &= t_mask - 1;
                count += 1;
            }
            if count != 4 {
                continue;
            }
        }

        // judge the numbers
        {
            let mut cv:Vec<i32> = vec![];
            for i in 0..nums.len() {
                if mask & (1 << i) != 0 {
                    cv.push(nums[i]);
                }
            }

            if cv[0] + cv[1] + cv[2] == cv[3] {
                ret += 1;
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = count_quadruplets(vec![1,1,1,3,5]);
        assert_eq!(ret, 4);
        let ret = count_quadruplets(vec![1,2,3,6]);
        assert_eq!(ret, 1);
        let ret = count_quadruplets(vec![3,3,6,4,5]);
        assert_eq!(ret, 0);
    }
}