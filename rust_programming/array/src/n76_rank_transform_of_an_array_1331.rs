
pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32>
{
    if arr.len() < 1 {
        return arr;
    }

    let mut ret:Vec<i32> = vec![0;arr.len()];
    let mut temp = ret.clone();
    let mut n:usize = 0;

    while n < arr.len() {
        temp[n] = n as i32 + 1;
        n += 1;
    }

    let mut dup_vec = arr.clone();

    for i in 0..arr.len() - 1 {
        for j in 0..arr.len() - i - 1 {
            if dup_vec[j] > dup_vec[j + 1] {
                let mut t = dup_vec[j + 1];
                dup_vec[j + 1] = dup_vec[j];
                dup_vec[j] = t;
                t = temp[j + 1];
                temp[j + 1] = temp[j];
                temp[j] = t;
            }
        }
    }

    for i in 0..arr.len() {
        ret[temp[i] as usize - 1] = i as i32 + 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = array_rank_transform(vec![40,10,20,30]);
        assert_eq!(ret, vec![4,1,2,3]);
        let ret = array_rank_transform(vec![37,13,28,9,100,56,80,5,12]);
        assert_eq!(ret, vec![6,4,5,2,9,7,8,1,3]);
    }
}