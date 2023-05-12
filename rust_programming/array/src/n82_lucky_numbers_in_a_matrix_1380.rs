
pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32>
{
    if matrix.len() < 1 || matrix[0].len() < 1 {
        return vec![];
    }

    let mut ret:Vec<i32> = vec![];
    let mut record:Vec<(i32, usize)> = vec![(0,0); matrix.len()];

    for i in 0..matrix.len() {
        let mut min:i32 = i32::MAX;
        for j in 0..matrix[i].len() {
            if matrix[i][j] < min {
                min = matrix[i][j];
                record[i] = (min, j);
            }
        }
    }

    for i in 0..matrix[0].len() {
        let mut max:i32 = i32::MIN;
        for j in 0..matrix.len() {
            if matrix[j][i] > max {
                max = matrix[j][i];
            }
        }
        if record.contains(&(max, i)) {
            ret.push(max);
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = lucky_numbers(vec![vec![1,10,4,2],vec![9,3,8,7],vec![15,16,17,12]]);
        assert_eq!(ret, vec![12]);
        let ret = lucky_numbers(vec![vec![7,8],vec![1,2]]);
        assert_eq!(ret, vec![7]);
    }
}