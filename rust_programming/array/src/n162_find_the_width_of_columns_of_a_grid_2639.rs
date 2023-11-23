
pub fn find_column_width(grid: Vec<Vec<i32>>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];
    if grid.len() < 1 {
        return ret;
    }

    let len = grid[0].len();
    for i in 0..len {
        let mut max_len:usize = usize::MIN;
        let mut col_len:usize;
        for j in 0..grid.len() {
            col_len = grid[j][i].to_string().len();
            max_len = max_len.max(col_len);
        }
        ret.push(max_len as i32);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = find_column_width(vec![vec![-15,1,3],vec![15,7,12],vec![5,6,-2]]);
        assert_eq!(ret, vec![3,1,2]);

        let ret = find_column_width(vec![vec![1],vec![22],vec![333]]);
        assert_eq!(ret, vec![3]);
    }
}