
pub fn find_center(edges: Vec<Vec<i32>>) -> i32
{
    if edges.is_empty() {
        return -1;
    }

    let mut ret:i32 = 0;
    let mut flag:bool = false;
    for i in 0..edges[0].len() {
        ret = edges[0][i];
        for j in 1..edges.len() {
            if !edges[j].contains(&ret) {
                flag = true;
                break;
            }
        }
        if flag == false {
            return ret;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = find_center(vec![vec![1,2],vec![2,3],vec![4,2]]);
        assert_eq!(ret, 2);
        let ret = find_center(vec![vec![1,2],vec![5,1],vec![1,3],vec![1,4]]);
        assert_eq!(ret, 1);
    }
}