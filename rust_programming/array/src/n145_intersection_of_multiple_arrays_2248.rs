
fn find_common_elements(a:&Vec<i32>, b:&Vec<i32>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];

    for e in a {
        if b.contains(&e) && !ret.contains(&e) {
            ret.push(*e);
        }
    }

    return ret;
}

pub fn intersection(nums: Vec<Vec<i32>>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];
    if nums.is_empty() {
        return ret;
    }

    ret = nums[0].clone();
    for i in 1..nums.len() {
        ret = find_common_elements(&ret, &nums[i]);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = intersection(vec![vec![3,1,2,4,5],vec![1,2,3,4],vec![3,4,5,6]]);
        assert_eq!(ret, vec![3,4]);
        let ret = intersection(vec! [vec![1,2,3], vec![4,5,6]]);
        assert_eq!(ret, vec![]);
    }
}