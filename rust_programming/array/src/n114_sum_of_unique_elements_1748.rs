use std::{collections::HashMap};

pub fn sum_of_unique(nums: Vec<i32>) -> i32
{
    if nums.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;
    let mut hashmap:HashMap<i32, usize> = HashMap::new();

    for i in 0..nums.len() {
        let mut count = 0;
        if hashmap.contains_key(&nums[i]) {
            count = 1;
        }
        *hashmap.entry(nums[i]).or_default() += count;
    }

    hashmap.iter().fold(0, |sum: i32, (x, v) | {
        if *v == 0 {
            ret = sum + *x;
        }
        ret
    });

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = sum_of_unique(vec![1,2,3,2]);
        assert_eq!(ret, 4);
        let ret = sum_of_unique(vec![1,1,1,1,1]);
        assert_eq!(ret, 0);
        let ret = sum_of_unique(vec! [1,2,3,4,5]);
        assert_eq!(ret, 15);
    }
}