
pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>>
{
    let mut ret:Vec<Vec<i32>> = vec![vec![]];

    if original.len() < 1 || m * n != original.len() as i32 {
        return ret;
    }

    ret = vec![vec![0; n as usize]; m as usize];

    for i in 0..(m) as usize {
        for j in 0..(n) as usize {
            ret[i][j] = original[j + i*(n as usize)];
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = construct2_d_array(vec![1,2,3], 1, 3);
        assert_eq!(ret, vec![vec![1,2,3]]);
        let ret = construct2_d_array(vec![1,2,3,4], 2, 2);
        assert_eq!(ret, vec![vec![1,2],vec![3,4]]);
        let ret = construct2_d_array(vec![1,2], 1, 1);
        assert_eq!(ret, vec![vec![]]);
    }
}