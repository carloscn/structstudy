use std::collections::BinaryHeap;

pub fn fill_cups(amount: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if amount.len() < 1 {
        return ret;
    }
    let mut pq: BinaryHeap<_> = amount.into_iter().collect();
    while let Some(x) = pq.pop() {
        if x == 0 {
            break;
        } else if let Some(y) = pq.pop() {
            ret += 1;
            pq.push(x - 1);
            pq.push(y - 1);
        } else {
            ret += x;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = fill_cups(vec![1,4,2]);
        assert_eq!(ret, 4);

        let ret = fill_cups(vec![5,4,4]);
        assert_eq!(ret, 7);

        let ret = fill_cups(vec![5,0,0]);
        assert_eq!(ret, 5);
    }
}