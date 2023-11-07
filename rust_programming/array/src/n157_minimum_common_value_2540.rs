
pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32
{
    let mut ret:i32 = -1;

    if nums1.is_empty() || nums2.is_empty() {
        return ret;
    }

    let mut i:usize = 0;
    let mut j:usize = 0;
    while i < nums1.len() && j < nums2.len() {
        if nums1[i] == nums2[j] {
            ret = nums1[i];
            break;
        } else if nums1[i] < nums2[j] {
            i += 1;
        } else {
            j += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = get_common(vec![1,2,3], vec![2,4]);
        assert_eq!(ret, 2);

        let ret = get_common(vec![1,2,3,6], vec![2,3,4,5]);
        assert_eq!(ret, 2);

        let ret = get_common(vec![1,2,3,4], vec![5,6,7,8]);
        assert_eq!(ret, -1);
    }
}