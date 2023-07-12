use std::collections::HashMap;

pub fn count_good_rectangles(rectangles: Vec<Vec<i32>>) -> i32
{
    if rectangles.len() < 1 {
        return 0;
    }

    let ret:i32;
    let mut r_v:Vec<i32> = vec![];

    for e in rectangles {
        let min = e.iter().fold(i32::MAX, |a: i32, b| a.min(*b));
        r_v.push(min);
    }

    // find max frequency of an element in the vector
    let mut m:HashMap<i32, usize> = HashMap::new();
    for x in &r_v {
        *m.entry(*x).or_default() += 1;
    }

    let max_freq = m.into_iter()
                         .max_by_key(|(_, v)| *v)
                         .map(|(k, _) | k)
                         .unwrap() as i32;

    // // optional:
    // let max_freq = r_v.clone().into_iter()
    //                   .fold(HashMap::<i32, i32>::new(), |mut m, x| {
    //                         *m.entry(x).or_default() += 1; m })
    //                   .into_iter()
    //                   .max_by_key(|(_, v)| *v)
    //                   .map(|(k, _) | k)
    //                   .unwrap();

    // count number of max frequency of an element in the vector
    ret = r_v.iter().fold(0, |count, b| {
        if *b == max_freq {
            count + 1
        } else {
            count
        }
    });

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = count_good_rectangles(vec![vec![5,8],vec![3,9],vec![5,12],vec![16,5]]);
        assert_eq!(ret, 3);
        let ret = count_good_rectangles(vec![vec![2,3],vec![3,7],vec![4,3],vec![3,7]]);
        assert_eq!(ret, 3);
    }
}