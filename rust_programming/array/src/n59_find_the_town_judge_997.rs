
pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32
{
    if 0 == trust.len() || 0 == n {
        return -1;
    }
    let mut aux:Vec<i32> = vec![0;(n + 1) as usize];

    for i in 0..trust.len() {
        aux[trust[i][0] as usize] -= 1;
        aux[trust[i][1] as usize] += 1;
    }

    for i in 1..(aux.len()) {
        if aux[i] == n - 1 {
            return i as i32;
        }
    }

    return -1;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let ret = find_judge(3,vec![
            vec![1, 3],
            vec![2, 3]]);
        assert_eq!(ret, 3); // pass

        let ret = find_judge(3,vec![
            vec![1, 2],
            vec![1, 3],
            vec![2, 3]]);
        assert_eq!(ret, 3); // all trust 3, 3 don't trust others., pass

        let ret = find_judge(3,vec![
            vec![1, 2],
            vec![1, 3],
            vec![1, 1]]);
        assert_eq!(ret, -1); // 2 cannot trust 3, failed

        let ret = find_judge(3,vec![
            vec![1, 2],
            vec![2, 3],
            vec![3, 1]]);
        assert_eq!(ret, -1); // 3 trusted 1, failed
    }

    #[test]
    fn test_find_judge() {
        // Test case 1
        let n1 = 2;
        let trust1 = vec![vec![1,2]];
        assert_eq!(find_judge(n1, trust1), 2);

        // Test case 2
        let n2 = 3;
        let trust2 = vec![vec![1,3],vec![2,3]];
        assert_eq!(find_judge(n2, trust2), 3);

        // Test case 3
        let n3 = 3;
        let trust3 = vec![vec![1,3],vec![2,3],vec![3,1]];
        assert_eq!(find_judge(n3, trust3), -1);

        // Test case 4
        let n4 = 3;
        let trust4 = vec![vec![1,2],vec![2,3]];
        assert_eq!(find_judge(n4, trust4), -1);

        // Test case 5
        let n5 = 4;
        let trust5 = vec![vec![1,3],vec![1,4],vec![2,3],vec![2,4],vec![4,3]];
        assert_eq!(find_judge(n5, trust5), 3);
    }
}