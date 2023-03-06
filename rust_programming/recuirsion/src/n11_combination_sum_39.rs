use utils::stack::Stack;

fn helper(array:&Vec<i64>, reslist:&mut Vec<Vec<i64>>, stack:&mut Stack<i64>, k:usize, target:i64, n:usize)
{
    if k > n {
        return;
    }
    //stack.print();

    if stack.sum() == target {
        let v_e = stack.dup_vector();
        reslist.push(v_e);
        return;
    }

    stack.push(array[k]);
    helper(array, reslist, stack, k + 1, target, n);
    stack.pop();
}

fn comb_sum(array:&Vec<i64>, target:i64) -> Vec<Vec<i64>>
{
    let mut reslist:Vec<Vec<i64>> = vec![];
    let mut dup_array:Vec<i64> = vec![];
    let mut i:usize = 0;
    let mut sum:i64;
    let mut j:usize = 0;
    let mut e:&i64;
    let mut stack:Stack<i64> = Stack::new();

    while i < array.len() {
        sum = 0;
        e = &array[i];
        while sum < target {
            dup_array.push(*e);
            sum += *e;
            j += 1;
        }
        i += 1;
    }

    i = 0;
    dup_array.sort();
    dup_array.push(0);

    while i < dup_array.len() - 1 {
        helper(&dup_array, &mut reslist, &mut stack, i, target, dup_array.len() - 1);
        i += 1;
    }

    return reslist;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_comb_sum_0() {
        let array = vec![2,3,6,7];
        let mut ret = comb_sum(&array, 7);
        assert_eq!(ret, vec![vec![2,2,3], vec![7]]);
    }

    #[test]
    pub fn test_comb_sum_1() {
        let array = vec![2,3,5];
        let mut ret = comb_sum(&array, 8);
        assert_eq!(ret, vec![vec![2,2,2,2], vec![2,3,3], vec![3,5]]);
    }
}