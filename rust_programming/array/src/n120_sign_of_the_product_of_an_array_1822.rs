
pub fn array_sign(nums: Vec<i32>) -> i32
{
    if nums.len() < 1 {
        return 0;
    }

    let ret:i32 = nums.iter().fold(1, | mut count, &x | {
        if x < 0 {
            count *= -1;
        } else if x == 0 {
            count = 0;
        }
        count
    });

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = array_sign(vec![-1,-2,-3,-4,3,2,1]);
        assert_eq!(ret, 1);
        let ret = array_sign(vec![-1,1,-1,1,-1]);
        assert_eq!(ret, -1);
        let ret = array_sign(vec![1,5,0,2,-3]);
        assert_eq!(ret, 0);
    }
}