
pub fn answer_queries(nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];
    if nums.len() < 1 || queries.len() < 1 {
        return ret;
    }

    let mut nums_dup = nums.clone();

    // [1] sort input values in place
    nums_dup.sort_unstable();

    // [2] compute cumsums in place
    let mut acc = 0;
    let sums: Vec<i32> = nums_dup.into_iter().map(|num| { acc += num; acc }).collect::<Vec<i32>>();

    // [3] for a sorted list of cumsums, we can quickly find the index using binary search
    ret = queries.into_iter().map(|q| match sums.binary_search(&q) {
        Ok(i) => i + 1,
        Err(i) => i,
    } as i32).collect::<Vec<_>>();

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = answer_queries(vec![4,5,2,1], vec![3,10,21]);
        assert_eq!(ret, vec![2,3,4]);

        let ret = answer_queries(vec![2,3,4,5], vec![3,10,21]);
        assert_eq!(ret, vec![2,3,4]);
    }
}