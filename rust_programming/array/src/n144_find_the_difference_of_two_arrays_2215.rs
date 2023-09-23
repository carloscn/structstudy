
pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>>
{
    let mut ret:Vec<Vec<i32>> = vec![];
    if nums1.is_empty() || nums2.is_empty() {
        return ret;
    }

    let mut v1:Vec<i32> = vec![];
    for e in &nums1 {
        if !nums2.contains(e) && !v1.contains(e) {
            v1.push(*e);
        }
    }
    ret.push(v1);

    let mut v2:Vec<i32> = vec![];
    for e in &nums2 {
        if !nums1.contains(e) && !v2.contains(e){
            v2.push(*e);
        }
    }
    ret.push(v2);

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = find_difference(vec![1,2,3], vec![2,4,6]);
        assert_eq!(ret, vec![vec![1,3],vec![4,6]]);

        let ret = find_difference(vec![1,2,3,3], vec![1,1,2,2]);
        assert_eq!(ret, vec![vec![3],vec![]]);
    }
}