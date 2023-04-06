
pub fn largest_sum_after_k_negations(nums: Vec<i32>, k: i32) -> i32
{
    let mut sum:i32 = 0;

    if nums.len() < 1 {
        return sum;
    }

    let mut nums_dup = nums.clone();

    nums_dup.sort();

    for i in 0..k {
        nums_dup[0] *= -1;
        nums_dup.sort();
    }

    for i in 0..nums.len() {
        sum += nums_dup[i];
    }

    return sum;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let nums = vec![2,-3,-1,5,-4];
        let k = 2;
        let ret = largest_sum_after_k_negations(nums, k);
        assert_eq!(ret, 13);
    }

    #[test]
    fn test_largest_sum_after_k_negations() {
        assert_eq!(largest_sum_after_k_negations(vec![4,2,3], 1), 5);
        assert_eq!(largest_sum_after_k_negations(vec![3,-1,0,2], 3), 6);
        assert_eq!(largest_sum_after_k_negations(vec![2,-3,-1,5,-4], 2), 13);
        assert_eq!(largest_sum_after_k_negations(vec![1,-1,1,1], 2), 2);
    }
}