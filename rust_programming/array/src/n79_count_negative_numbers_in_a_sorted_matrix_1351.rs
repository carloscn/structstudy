
pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32
{
    if grid.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;

    for e in grid {
        for i in 0..e.len() {
            if e[e.len() - i - 1] < 0 {
                ret += 1;
            } else {
                break;
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = count_negatives(vec![vec![4,3,2,-1],vec![3,2,1,-1],vec![1,1,-1,-2],vec![-1,-1,-2,-3]]);
        assert_eq!(ret, 8);
        let ret = count_negatives(vec![vec![3,2],vec![1,0]]);
        assert_eq!(ret, 0);
    }
}