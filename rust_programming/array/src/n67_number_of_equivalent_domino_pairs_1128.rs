
fn is_equal(a:&Vec<i32>, b:&Vec<i32>) -> bool
{
    if a.len() != b.len() && a.len() != 2{
        return false;
    }

    if (a[0] == b[0] && a[1] == b[1]) ||
       (a[0] == b[1] && a[1] == b[0]) {
        return true;
    }

    return false;
}

pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32
{
    let mut ret:i32 = 0;

    if dominoes.len() < 2 {
        return ret;
    }

    let mut i:usize = 0;
    let mut j:usize = 0;

    for i in 0..dominoes.len() {
        for j in (i + 1)..dominoes.len() {
            if is_equal(&dominoes[i], &dominoes[j]) {
                ret += 1;
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let dom = vec![vec![1,2],vec![2,1],vec![1,2],vec![1,2]];
        let ret = num_equiv_domino_pairs(dom);
        assert_eq!(ret, 6);
    }

    #[test]
    fn test_num_equiv_domino_pairs() {
        let dominoes = vec![
            vec![1, 2],
            vec![2, 1],
            vec![3, 4],
            vec![5, 6],
        ];

        assert_eq!(num_equiv_domino_pairs(dominoes), 1);
        assert_eq!(num_equiv_domino_pairs(vec![vec![1, 2], vec![2, 1], vec![3, 4], vec![5, 6]]), 1);
        assert_eq!(num_equiv_domino_pairs(vec![vec![1, 2], vec![2, 1], vec![1, 2], vec![2, 1], vec![1, 2], vec![2, 1]]), 15);
    }
}