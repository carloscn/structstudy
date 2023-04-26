
fn increase_row(inv:&mut Vec<Vec<i32>>, row_num:usize)
{
    for i in 0..inv[0].len() {
        inv[row_num][i] += 1;
    }
}

fn increase_col(inv:&mut Vec<Vec<i32>>, col_num:usize)
{
    for i in 0..inv.len() {
        inv[i][col_num] += 1;
    }
}

pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32
{
    let mut ret:i32 = 0;

    if m < 1 || n < 1 || indices.len() < 1 {
        return ret;
    }

    let mut inv:Vec<Vec<i32>> = vec![];

    for i in 0..m {
        let mut t:Vec<i32> = vec![0; n as usize];
        inv.push(t);
    }

    for e in &indices {
        increase_row(&mut inv, e[0] as usize);
        increase_col(&mut inv, e[1] as usize);
    }

    for i in 0..inv.len() * inv[0].len() {
        if inv[i % inv.len()][i/inv.len()] & 0x1 == 1 {
            ret += 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut ret;
        ret = odd_cells(2, 3, vec![vec![0,1],vec![1,1]]);
        assert_eq!(ret, 6);

        ret = odd_cells(2, 2, vec![vec![1,1],vec![0,0]]);
        assert_eq!(ret, 0);
    }
}