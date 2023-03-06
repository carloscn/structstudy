use utils::stack::Stack;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_comb_sum_0() {
        let array = vec![10,1,2,7,6,1,5];
        let mut ret = comb_sum(&array, 8);
        //assert_eq!(ret, vec![vec![2,2,3], vec![7]]);
    }
}


fn helper(array:&Vec<i64>,
          len:usize,
          stack:&mut Stack<i64>,
          reslist:&mut Vec<Vec<i64>>,
          k:usize,
          target:i64)
{
    if k > len - 1 {
        return;
    }

    stack.print();

    if (stack.sum() == target) {
        let v_c = stack.dup_vector();
        reslist.push(v_c);
        return;
    }

    let mut i:usize = k;

    while i < len {
        stack.push(array[i]);
        helper(array, len, stack, reslist, i + 1, target);
        stack.pop();
        i += 1;
    }
}

fn comb_sum(array:&Vec<i64>, target:i64) -> Vec<Vec<i64>>
{
    let mut reslist:Vec<Vec<i64>> = vec![];
    let mut dup_array:Vec<i64> = array.clone();
    let mut stack:Stack<i64> = Stack::new();

    if 0 == dup_array.len() {
        return reslist;
    }

    dup_array.sort();
    dup_array.reverse();

    helper(array, dup_array.len(), &mut stack, &mut reslist, 0, target);

    // filter_dup_logic()

    println!("the result is {:?}", reslist);

    return reslist;
}