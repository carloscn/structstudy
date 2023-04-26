
pub fn shift_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>>
{
    if k == 0 {
        return grid;
    }

    let len:usize = grid.len();
    let r_len:usize = grid[0].len();
    if len < 1 || r_len < 1 {
        return vec![];
    }

    let mut row:Vec<i32> = vec![];
    let mut ret_vec:Vec<Vec<i32>> = vec![];

    // 2D VEC conversion to one-dimensional
    for e in grid {
        row.append(&mut e.clone());
    }

    // shift K len element
    let mut k_shifted_vec:Vec<i32> = row.drain(row.len() - (k as usize)..row.len()).collect();
    k_shifted_vec.append(&mut row);

    // convert to rows
    for i in 0..len {
        ret_vec.push(k_shifted_vec.drain(0..r_len).collect());
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = shift_grid(vec![vec![1,2,3],vec![4,5,6],vec![7,8,9]], 1);
        assert_eq!(ret, vec![vec![9,1,2],vec![3,4,5],vec![6,7,8]]);

        ret = shift_grid(vec![vec![3,8,1,9],vec![19,7,2,5],vec![4,6,11,10],vec![12,0,21,13]], 4);
        assert_eq!(ret, vec![vec![12,0,21,13],vec![3,8,1,9],vec![19,7,2,5],vec![4,6,11,10]]);
    }
}