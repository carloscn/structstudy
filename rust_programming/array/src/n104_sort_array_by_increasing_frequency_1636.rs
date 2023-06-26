
pub fn frequency_sort(nums: Vec<i32>) -> Vec<i32>
{
    if nums.len() < 1 {
        return nums;
    }

    let mut ret:Vec<i32> = vec![];
    let mut queue:Vec<(usize, i32)> = vec![];
    let mut nums_dup:Vec<i32> = nums.clone();

    nums_dup.sort();
    nums_dup.push(0);

    let mut count:usize = 1;
    let mut e = nums_dup[0];

    for i in 1..nums_dup.len() {
        if e == nums_dup[i] {
            count += 1;
            continue;
        } else {
            queue.push((count, e));
            count = 1;
            e = nums_dup[i];
        }
    }

    for _i in 0..queue.len() {
        for j in 0..queue.len() - 1 {
            if (queue[j].0 > queue[j + 1].0) ||
               (queue[j].0 == queue[j + 1].0 && queue[j].1 < queue[j + 1].1) {
                let t = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = t;
            }
        }
    }

    for e in queue {
        for _i in 0..e.0 {
            ret.push(e.1);
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = frequency_sort(vec![1,1,2,2,2,3]);
        assert_eq!(ret, vec![3,1,1,2,2,2]);
        let mut ret = frequency_sort(vec![-1,1,-6,4,5,-6,1,4,1]);
        assert_eq!(ret, vec![5,-1,4,4,-6,-6,1,1,1]);
        let mut ret = frequency_sort(vec![2,3,1,3,2]);
        assert_eq!(ret, vec![1,3,3,2,2]);
    }
}