
pub fn min_subsequence(nums: Vec<i32>) -> Vec<i32>
{
    if nums.is_empty() {
        return nums;
    }

    if nums.len() == 1 {
        return nums;
    }

    let mut ret:Vec<i32> = vec![];
    let mut nums_dup = nums.clone();

    for i in 0..nums_dup.len() {
        for j in 0..(nums_dup.len() - i - 1) {
            if nums_dup[j] < nums_dup[j + 1] {
                nums_dup[j] ^= nums_dup[j + 1];
                nums_dup[j + 1] ^= nums_dup[j];
                nums_dup[j] ^= nums_dup[j + 1];
            }
        }
    }

    for len in 1..nums_dup.len() {
        let mut win_sum:i32 = 0;
        let mut lef_sum:i32 = 0;

        for i in 0..len {
            win_sum += nums_dup[i];
        }

        for i in len..nums_dup.len() {
            lef_sum += nums_dup[i];
        }

        if win_sum > lef_sum {
            ret.append(&mut nums_dup[0..len].to_vec());
            break;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = min_subsequence(vec![4,3,10,9,8]);
        assert_eq!(ret, vec![10,9]);
        let mut ret = min_subsequence(vec![4,4,7,6,7]);
        assert_eq!(ret, vec![7,7,6]);
        let mut ret = min_subsequence(vec![6]);
        assert_eq!(ret, vec![6]);
    }
}