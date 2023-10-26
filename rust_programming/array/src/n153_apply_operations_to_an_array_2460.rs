
pub fn apply_operations(nums: Vec<i32>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];
    if nums.len() < 1 {
        return ret;
    }

    let mut nums_dup = nums.clone();

    for i in 0..nums.len() - 1 {
        if nums_dup[i] == nums_dup[i + 1] {
            nums_dup[i] *= 2;
            nums_dup[i + 1] = 0;
        }
    }

    let mut index:usize = 0;
    for i in 0..nums_dup.len() {
        if nums_dup[i] != 0 {
            ret.insert(index, nums_dup[i]);
            index += 1;
        } else {
            ret.push(0);
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = apply_operations(vec![1,2,2,1,1,0]);
        assert_eq!(ret, vec![1,4,2,0,0,0]);

        let ret = apply_operations(vec![0,1]);
        assert_eq!(ret, vec![1,0]);
    }
}