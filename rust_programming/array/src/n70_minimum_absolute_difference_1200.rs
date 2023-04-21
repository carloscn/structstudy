
pub fn minimum_abs_difference(arr: Vec<i32>) -> Vec<Vec<i32>>
{
    let mut ret_vec:Vec<Vec<i32>> = vec![];
    let mut in_vec:Vec<i32> = arr.clone();

    in_vec.sort();
    if arr.len() < 2 {
        return ret_vec;
    } else if arr.len() == 2 {
        ret_vec.push(in_vec);
        return ret_vec;
    }

    let mut r_min_diff:i32 = 0x7FFFFFFF;
    for i in 0..arr.len() - 1 {
        let e = in_vec[i + 1] - in_vec[i];
        let sub_vec:Vec<i32> = vec![in_vec[i], in_vec[i + 1]];
        if e > r_min_diff {
            continue;
        } else if e == r_min_diff {
            ret_vec.push(sub_vec);
        } else {
            ret_vec.clear();
            r_min_diff = e;
            ret_vec.push(sub_vec);
        }
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut arr = vec![3,8,-10,23,19,-4,-14,27];
        let mut ret;

        ret = minimum_abs_difference(arr);
        assert_eq!(ret, vec![vec![-14,-10],vec![19,23],vec![23,27]]);
    }

    #[test]
    fn test_minimum_abs_difference() {
        assert_eq!(minimum_abs_difference(vec![4, 2, 1, 3]), vec![vec![1, 2], vec![2, 3], vec![3, 4]]);
        assert_eq!(minimum_abs_difference(vec![1, 3, 6, 10, 15]), vec![vec![1, 3]]);
        assert_eq!(minimum_abs_difference(vec![3, 8, -10, 23, 19, -4, -14, 27]), vec![vec![-14, -10], vec![19, 23], vec![23, 27]]);
        assert_eq!(minimum_abs_difference(vec![1, 2, 3]), vec![vec![1, 2], vec![2, 3]]);
    }
}