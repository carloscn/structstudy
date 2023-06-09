
pub fn most_visited(n: i32, rounds: Vec<i32>) -> Vec<i32>
{
    if rounds.len() < 1 || n == 0 {
        return vec![];
    }

    let mut ret:Vec<i32> = vec![];

    for i in rounds[0]..rounds[rounds.len() - 1] + 1 {
        ret.push(i);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = most_visited(4, vec![1,3,1,2]);
        assert_eq!(ret, vec![1, 2]);
        let mut ret = most_visited(2, vec![2,1,2,1,2,1,2,1,2]);
        assert_eq!(ret, vec![2]);
        let mut ret = most_visited(7, vec![1,3,5,7]);
        assert_eq!(ret, vec![1,2,3,4,5,6,7]);
    }
}