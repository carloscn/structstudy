
fn transpose_matrix(mat:Vec<Vec<i32>>) -> Vec<Vec<i32>>
{
    let mut ret_vec = vec![];

    for i in 0..mat[0].len() {
        let mut new_vec:Vec<i32> = vec![];
        for vec in &mat {
            new_vec.push(vec[i]);
        }
        ret_vec.push(new_vec);
    }

    ret_vec
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    // [1, 2, 3]   -> [1, 4, 7]
    // [4, 5, 6]   -> [2, 5, 8]
    // [7, 8, 9]   -> [3, 6, 9]
    fn test_1() {
        let in_vec = vec![
                          vec![1,2,3],
                          vec![4,5,6],
                          vec![7,8,9]];
        let ot_vec = vec![
                          vec![1,4,7],
                          vec![2,5,8],
                          vec![3,6,9]];

        let ret_vec = transpose_matrix(in_vec);
        assert_eq!(ret_vec, ot_vec);
    }

    #[test]
    // [1, 2, 3]   -> [1, 4]
    // [4, 5, 6]   -> [2, 5]
    //             -> [3, 6]
    fn test_2() {
        let in_vec = vec![
                          vec![1,2,3],
                          vec![4,5,6]];
        let ot_vec = vec![
                          vec![1,4],
                          vec![2,5],
                          vec![3,6]];

        let ret_vec = transpose_matrix(in_vec);
        assert_eq!(ret_vec, ot_vec);
    }

    #[test]
    // [1, 2]   -> [1, 4, 6]
    // [4, 5]   -> [2, 5, 7]
    // [6, 7]
    fn test_3() {
        let in_vec = vec![
                          vec![1,2],
                          vec![4,5],
                          vec![6,7]];
        let ot_vec = vec![
                          vec![1,4,6],
                          vec![2,5,7]];

        let ret_vec = transpose_matrix(in_vec);
        assert_eq!(ret_vec, ot_vec);
    }
}