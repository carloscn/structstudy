
pub fn height_checker(heights: Vec<i32>) -> i32
{
    if heights.len() < 1 {
        return 0;
    }

    let mut hei_vec:Vec<i32> = heights.clone();
    let mut count:i32 = 0;
    let mut i:usize = 0;
    hei_vec.sort();

    for e in heights {
        if e != hei_vec[i] {
            count += 1;
        }
        i += 1;
    }

    return count;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_height_checker() {
        // test case 1: all heights are in increasing order
        let heights1 = vec![1, 2, 3, 4, 5];
        assert_eq!(height_checker(heights1), 0);

        // test case 2: all heights are in decreasing order
        let heights2 = vec![5, 4, 3, 2, 1];
        assert_eq!(height_checker(heights2), 4);

        // test case 3: some heights are not in increasing order
        let heights3 = vec![1, 3, 2, 4, 5];
        assert_eq!(height_checker(heights3), 2);

        // test case 4: some heights are equal
        let heights4 = vec![1, 3, 2, 4, 4];
        assert_eq!(height_checker(heights4), 2);

        // test case 5: empty input
        let heights5 = vec![];
        assert_eq!(height_checker(heights5), 0);
    }
}