

fn slop_value(a:&Vec<i32>, b:&Vec<i32>) -> i32
{
    return (b[1] - a[1]) / (b[0] - a[0]);
}

pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool
{
    if coordinates.len() == 0 {
        return false;
    }

    if coordinates.len() < 2 {
        return true;
    }

    let mut last_slop:i32 = slop_value(&coordinates[0], &coordinates[1]);
    for i in 1..coordinates.len() - 1 {
        let current_slop = slop_value(&coordinates[i], &coordinates[i + 1]);
        if last_slop != current_slop {
            return false;
        }
        last_slop = current_slop;
    }

    return true;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let mut ret = check_straight_line(vec![vec![1,2],vec![2,3],vec![3,4],vec![4,5],vec![5,6],vec![6,7]]);
        assert_eq!(ret, true);
        ret = check_straight_line(vec![vec![1,1],vec![2,2],vec![3,4],vec![4,5],vec![5,6],vec![7,7]]);
        assert_eq!(ret, false);
    }

    #[test]
    fn test_check_straight_line() {
        assert_eq!(check_straight_line(vec![vec![1,1], vec![2,2], vec![3,3], vec![4,4], vec![5,5], vec![6,6]]), true);
        assert_eq!(check_straight_line(vec![vec![1,2], vec![2,3], vec![3,4], vec![4,5], vec![5,6], vec![6,7]]), true);
        assert_eq!(check_straight_line(vec![vec![1,2], vec![2,3], vec![3,4], vec![4,5], vec![5,7], vec![6,7]]), false);
        assert_eq!(check_straight_line(vec![vec![1,1], vec![2,2], vec![4,4], vec![5,5], vec![6,6]]), true);
        assert_eq!(check_straight_line(vec![vec![1,1], vec![2,2], vec![4,4], vec![5,5], vec![6,7]]), false);
    }
}