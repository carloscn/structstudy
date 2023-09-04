use std::collections::HashSet;

fn check_intersection(a:&Vec<i32>, b:&Vec<i32>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];

    if a.len() < 1 || b.len() < 1 {
        return ret;
    }

    let set1:HashSet<_> = a.into_iter().collect();
    let set2:HashSet<_> = b.into_iter().collect();
    let intersection:HashSet<_> = set1.intersection(&set2).collect();

    ret = intersection.into_iter().map(|x| **x).collect();

    return ret;
}

pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32>
{
    if nums1.len() < 1 && nums2.len() < 1 && nums3.len() < 1 {
        return vec![];
    }

    let mut ret:Vec<i32> = vec![];

    ret.append(check_intersection(&nums1, &nums2).as_mut());
    ret.append(check_intersection(&nums1, &nums3).as_mut());
    ret.append(check_intersection(&nums2, &nums3).as_mut());

    ret.sort();
    ret.dedup();

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = two_out_of_three(vec![1,1,3,2], vec![2,3], vec![3]);
        assert_eq!(ret, vec![2, 3]);
        let ret = two_out_of_three(vec![3,1], vec![2,3], vec![1,2]);
        assert_eq!(ret, vec![1, 2, 3]);
        let ret = two_out_of_three(vec![1,2,2], vec![4,3,3], vec![5]);
        assert_eq!(ret, vec![]);
    }
}