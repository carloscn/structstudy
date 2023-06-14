
fn row_sum(mat: &Vec<Vec<i32>>, row_num:usize) -> i32
{
    let mut sum:i32 = 0;

    for i in 0..mat[row_num].len() {
        sum += mat[row_num][i];
    }

    return sum;
}

fn col_sum(mat: &Vec<Vec<i32>>, col_num:usize) -> i32
{
    let mut sum:i32 = 0;

    for i in 0..mat.len() {
        sum += mat[i][col_num];
    }

    return sum;
}

pub fn num_special(mat: Vec<Vec<i32>>) -> i32
{
    if mat.len() < 1 || mat[0].len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;

    for i in 0..mat[0].len() * mat.len() {
        let c_i:usize = i / mat.len();
        let r_i:usize = i % mat[0].len();
        if (mat[c_i][r_i] == 1) &&
           (col_sum(&mat, c_i) + row_sum(&mat, r_i)) == 2 {
            ret += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use std::num;

    use super::*;

    #[test]
    fn demo() {
        let mut ret = 0;
        let mat =  vec![
                   vec![1,0,0],
                   vec![0,0,1],
                   vec![1,0,0]
        ];
        ret = num_special(mat);
        assert_eq!(ret, 1);

        let mat = vec![
                   vec![1,0,0],
                   vec![0,1,0],
                   vec![0,0,1]
        ];
        ret = num_special(mat);
        assert_eq!(ret, 3);

        let mat = vec![
                    vec![0,0,0,1],
                    vec![1,0,0,0],
                    vec![0,1,1,0],
                    vec![0,0,0,0]
        ];
        ret = num_special(mat);
        assert_eq!(ret, 2);

        let mat = vec![
                    vec![0,0,0,0,0],
                    vec![1,0,0,0,0],
                    vec![0,1,0,0,0],
                    vec![0,0,1,0,0],
                    vec![0,0,0,1,1]
        ];
        ret = num_special(mat);
        assert_eq!(ret, 3);
    }
}