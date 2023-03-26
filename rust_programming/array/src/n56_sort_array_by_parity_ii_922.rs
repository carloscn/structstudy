pub fn sort_array_by_parity_ii(nums: Vec<i32>) -> Vec<i32>
{
    let mut ret_vec:Vec<i32> = vec![];
    let odd_vec:Vec<i32> = nums.iter()
                               .filter(|x| *x & 1 == 1)
                               .map(|x| *x)
                               .collect();
    let even_vec:Vec<i32> = nums.iter()
                                .filter(|x| *x & 1 == 0)
                                .map(|x| *x)
                                .collect();

    if odd_vec.len() != even_vec.len() {
        return ret_vec;
    }

    for i in 0..odd_vec.len() {
        ret_vec.push(odd_vec[i]);
        ret_vec.push(even_vec[i]);
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let ret = sort_array_by_parity_ii(vec![4,2,5,7]);
        println!("the ret is {:?}", ret);
    }
    #[test]
    fn test_sort_array_by_parity_ii() {
        // Test case 1: An empty array should return an empty array
        assert_eq!(sort_array_by_parity_ii(vec![]), vec![]);

        // Test case 2: An array with alternating even and odd numbers should be sorted
        assert_eq!(
            sort_array_by_parity_ii(vec![2, 1, 4, 3, 6, 5]),
            vec![1,2,3,4,5,6]
        );

        // Test case 3: An array with alternating odd and even numbers should be sorted
        assert_eq!(
            sort_array_by_parity_ii(vec![1, 2, 3, 4, 5, 6]),
            vec![1,2,3,4,5,6]
        );

        // Test case 4: An array with more even numbers should return an empty array
        assert_eq!(sort_array_by_parity_ii(vec![2, 4, 6, 1, 8]), vec![]);

        // Test case 5: An array with more odd numbers should return an empty array
        assert_eq!(sort_array_by_parity_ii(vec![1, 3, 5, 2, 7]), vec![]);

    }

}
