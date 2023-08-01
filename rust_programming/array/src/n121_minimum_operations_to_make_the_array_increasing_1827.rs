
pub fn min_operations(nums: Vec<i32>) -> i32
{
    if nums.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;
    let mut ns = nums.clone();

    ns.push(0);
    for i in 0..ns.len() - 2 {
        if ns[i + 1] <= ns[i] {
            ret += ns[i] - ns[i + 1] + 1;
            ns[i + 1] = ns[i] + 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = min_operations(vec![1,1,1]);
        assert_eq!(ret, 3);
        let ret = min_operations(vec![1,5,2,4,1]);
        assert_eq!(ret, 14);
        let ret = min_operations(vec![8]);
        assert_eq!(ret, 0);
    }
}