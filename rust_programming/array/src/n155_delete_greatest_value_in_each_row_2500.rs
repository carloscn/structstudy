
pub fn delete_greatest_value(grid: Vec<Vec<i32>>) -> i32
{
    let mut ret:i32 = 0;

    if grid.len() < 1 {
        return ret;
    }

    if grid.len() == 1 {
        return grid[0][0];
    }

    let mut line_max:i32 = i32::MIN;
    let mut grid_dup = grid.clone();
    while grid_dup[0].len() != 1 {
        for e in &mut grid_dup {
            if let Some(max_index) = e
                .iter()
                .enumerate()
                .max_by_key(|&(_, &value)| value)
            {
                let (index, _) = max_index;
                line_max = e.remove(index).max(line_max);
            }
        }
        ret += line_max;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = delete_greatest_value(vec![vec![1,2,4],vec![3,3,1]]);
        assert_eq!(ret, 8);

        let ret = delete_greatest_value(vec![vec![10]]);
        assert_eq!(ret, 10);
    }
}