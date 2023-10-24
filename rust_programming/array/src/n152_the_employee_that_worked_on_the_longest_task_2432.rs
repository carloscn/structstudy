
pub fn hardest_worker(n: i32, logs: Vec<Vec<i32>>) -> i32
{
    let mut ret:i32 = 0;

    if logs.len() < 1 {
        return ret;
    }

    ret = i32::MIN;
    let mut index:usize = 0;
    for i in 0..logs.len() {
        let unit_time:i32;
        if i == 0 {
            unit_time = logs[i][1];
        } else {
            unit_time = logs[i][1] - logs[i - 1][1];
        }

        if unit_time > ret {
            ret = unit_time;
            index = i;
        }
    }

    ret = logs[index][0];

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = hardest_worker(10, vec![vec![0,3],vec![2,5],vec![0,9],vec![1,15]]);
        assert_eq!(ret, 1);

        let ret = hardest_worker(26, vec![vec![1,1],vec![3,7],vec![2,12],vec![7,17]]);
        assert_eq!(ret, 3);

        let ret = hardest_worker(2, vec![vec![0,10],vec![1,20]]);
        assert_eq!(ret, 0);
    }
}