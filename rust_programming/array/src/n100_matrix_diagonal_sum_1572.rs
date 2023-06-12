
pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32
{
    if mat.is_empty() || mat.len() != mat[0].len() {
        return 0;
    }

    let mut ret:i32 = 0;

    for i in 0..mat.len() {
        ret += mat[i][i];
        ret += mat[i][mat.len() - i - 1];
        if (i & 0x1 == 1) &&
           (mat.len() / 2) as i32 == i as i32 {
            ret -= mat[i][i];
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let v = vec![vec![1,2,3],
                                    vec![4,5,6],
                                    vec![7,8,9]];
        let ret = diagonal_sum(v);
        assert_eq!(ret, 25);
        let v = vec![vec![1,1,1,1],
                                    vec![1,1,1,1],
                                    vec![1,1,1,1],
                                    vec![1,1,1,1]];
        let ret = diagonal_sum(v);
        assert_eq!(ret, 8);
    }
}