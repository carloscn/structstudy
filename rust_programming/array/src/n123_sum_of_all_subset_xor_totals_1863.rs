
pub fn subset_xor_sum(nums: Vec<i32>) -> i32
{
    let len:usize = nums.len();

    if len < 1 {
        return 0;
    }

    let mut ret:i32 = 0;
    let (mut num, mut n, mut j, mut k) =
        (1 << len, 0, 0, 0);

    for i in 0..num {
        j = i;
        k = 0 as usize;
        n = 0 as usize;
        let mut t_buf:Vec<i32> = vec![0; i];
        while j != 0 {
            if j & 1 == 1  {
                t_buf[n] = nums[k];
                n += 1;
            }
            j >>= 1;
            k += 1;
        }
        let mut xor_sum:i32 = 0;
        for e in t_buf {
            xor_sum ^= e;
        }
        ret += xor_sum;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = subset_xor_sum(vec![1,3]);
        assert_eq!(ret, 6);
        let ret = subset_xor_sum(vec![5,1,6]);
        assert_eq!(ret, 28);
        let ret = subset_xor_sum(vec![3,4,5,6,7,8]);
        assert_eq!(ret, 480);
    }
}