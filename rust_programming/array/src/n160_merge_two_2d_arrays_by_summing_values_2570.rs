
pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>>
{
    let mut ret:Vec<Vec<i32>> = vec![];
    if nums1.len() < 1 && nums2.len() < 1 {
        return ret;
    }

    let (m, n) = (nums1.len(), nums2.len());
    let (mut i, mut j) = (0, 0);
    while i < m || j < n {
        if i < m && j < n && nums1[i][0] == nums2[j][0] {
            ret.push(vec![nums1[i][0], nums1[i][1] + nums2[j][1]]);
            i += 1;
            j += 1;
            continue;
        }

        if j == n || (i < m && nums1[i][0] < nums2[j][0]) {
            ret.push(nums1[i].clone());
            i += 1;
            continue;
        }

        ret.push(nums2[j].clone());
        j += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = merge_arrays(vec![vec![1,2],vec![2,3],vec![4,5]], vec![vec![1,4],vec![3,2],vec![4,1]]);
        assert_eq!(ret, vec![vec![1,6],vec![2,3],vec![3,2],vec![4,6]]);

        let ret = merge_arrays(vec![vec![2,4],vec![3,6],vec![5,5]], vec![vec![1,3],vec![4,3]]);
        assert_eq!(ret, vec![vec![1,3],vec![2,4],vec![3,6],vec![4,3],vec![5,5]]);
    }
}