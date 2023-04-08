
pub fn last_stone_weight(stones: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if stones.len() < 1 {
        return ret;
    }

    let mut stones_vec = stones.clone();

    stones_vec.sort();

    while stones_vec.len() > 1 {
        let e1 = stones_vec.pop().unwrap();
        let e2 = stones_vec.pop().unwrap();
        if e1 - e2 != 0 {
            stones_vec.insert(0, i32::abs(e1 - e2));
            stones_vec.sort();
        }
    }

    if stones_vec.len() != 0 {
        ret = stones_vec.pop().unwrap();
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let ret = last_stone_weight(vec![2,7,4,1,8,1]);
        assert_eq!(ret, 1);
    }

    #[test]
    fn test_last_stone_weight() {
        let test_cases = vec![
            (vec![2, 7, 4, 1, 8, 1], 1),
            (vec![2, 2], 0),
            (vec![1], 1),
            (vec![1, 3, 3, 4, 5, 6], 0),
            (vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 1),
        ];

        for (stones, expected) in test_cases {
            assert_eq!(last_stone_weight(stones), expected);
        }
    }
}