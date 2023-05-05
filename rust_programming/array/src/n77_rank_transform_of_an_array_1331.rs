use std::collections::HashMap;

pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32>
{
    if arr.len() < 1 {
        return arr;
    }

    let mut dup_vec = arr.clone();
    for i in 0..arr.len() - 1 {
        for j in 0..arr.len() - i - 1 {
            if dup_vec[j] > dup_vec[j + 1] {
                let t = dup_vec[j + 1];
                dup_vec[j + 1] = dup_vec[j];
                dup_vec[j] = t;
            }
        }
    }

    let mut n:usize = 0;
    let mut m:usize = 0;
    let mut hash:HashMap<i32, usize> = HashMap::new();
    while n < arr.len() {
        if !hash.contains_key(&dup_vec[n]) {
            hash.insert(dup_vec[n], m + 1);
            m += 1;
        }
        n += 1;
    }

    let mut ret:Vec<i32> = vec![0;arr.len()];
    for i in 0..arr.len() {
        ret[i] = (*hash.get(&arr[i]).unwrap()) as i32;
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = array_rank_transform(vec![40,10,10,20]);
        assert_eq!(ret, vec![3,1,1,2]);
        let ret = array_rank_transform(vec![37,13,28,9,100,56,80,5,12]);
        assert_eq!(ret, vec![6,4,5,2,9,7,8,1,3]);
        let ret = array_rank_transform(vec![100,100,100]);
        assert_eq!(ret, vec![1,1,1]);
        let ret = array_rank_transform(vec![37,12,28,9,100,56,80,5,12]);
        assert_eq!(ret, vec![5,3,4,2,8,6,7,1,3]);
    }
}