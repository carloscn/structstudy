
pub fn minimum_operations(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;
    if nums.len() < 1 || (nums.len() == 1 && nums[0] == 0) {
        return ret;
    }
    let mut input = nums.clone();

    loop {
        let min_value = input.iter().fold(i32::MAX, |mut min, x| {
            if *x != 0 && *x < min {
                min = *x;
            }
            min
        });

        let mut count_zero:usize = 0;
        for i in 0..input.len() {
            input[i] = (input[i] - min_value).max(0);
            if input[i] == 0 {
                count_zero += 1;
            }
        }

        ret += 1;
        if count_zero == nums.len() {
            break;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = minimum_operations(vec![1,5,0,3,5]);
        assert_eq!(ret, 3);
        let ret = minimum_operations(vec![0]);
        assert_eq!(ret, 0);
    }
}