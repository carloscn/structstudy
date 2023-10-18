
pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>>
{
    let mut ret:Vec<Vec<i32>> = vec![];

    if items1.len() < 1 && items2.len() < 1 {
        return ret;
    }

    let mut tv = items1.clone();

    tv.append(&mut items2.clone());
    tv.push(vec![i32::MAX, 0]);
    tv.sort();

    let mut i:usize = 0;
    while i < tv.len() - 1 {
        let mut e: Vec<i32> = vec![0; 2];
        e[0] = tv[i][0];
        if tv[i][0] == tv[i + 1][0] {
            e[1] = tv[i][1] + tv[i + 1][1];
            i += 2;
        } else {
            e[1] = tv[i][1];
            i += 1;
        }
        ret.push(e);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = merge_similar_items(
                            vec![vec![1,1],vec![4,5],vec![3,8]],
                            vec![vec![3,1],vec![1,5]]);
        assert_eq!(ret, vec![vec![1,6],vec![3,9],vec![4,5]]);

        let ret = merge_similar_items(
                            vec![vec![1,1],vec![3,2],vec![2,3]],
                            vec![vec![2,1],vec![3,2],vec![1,3]]);
        assert_eq!(ret, vec![vec![1,4],vec![2,4],vec![3,4]]);

        let ret = merge_similar_items(
                            vec![vec![1,3],vec![2,2]],
                            vec![vec![7,1],vec![2,2],vec![1,4]]);
        assert_eq!(ret, vec![vec![1,7],vec![2,4],vec![7,1]]);
    }
}