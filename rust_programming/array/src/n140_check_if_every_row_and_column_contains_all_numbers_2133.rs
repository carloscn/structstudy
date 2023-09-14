
fn check_all_in_vec(input:&Vec<i32>) -> bool
{
    let mut rom:Vec<i32> = vec![0;input.len() + 1];

    for e in input {
        rom[*e as usize] += 1;
    }

    for i in 1..rom.len() {
        if rom[i] == 0 {
            return false;
        }
    }

    return true;
}

pub fn check_valid(matrix: Vec<Vec<i32>>) -> bool
{
    if matrix.len() < 1 && matrix[0].len() < 1 {
        return false;
    }

    for e in &matrix {
        let ret = check_all_in_vec(e);
        if ret == false {
            return false;
        }
    }

    for i in 0..matrix[0].len() {
        let mut e_vec:Vec<i32> = vec![];
        for j in 0..matrix.len() {
            e_vec.push(matrix[j][i]);
        }
        let ret = check_all_in_vec(&e_vec);
        if ret == false {
            return false;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = check_valid(vec![vec![1,2,3],vec![3,1,2],vec![2,3,1]]);
        assert_eq!(ret, true);
        let ret = check_valid(vec![vec![1,1,1],vec![1,2,3],vec![1,2,3]]);
        assert_eq!(ret, false);
    }
}