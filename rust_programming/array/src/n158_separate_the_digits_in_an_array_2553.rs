pub fn separate_digits(nums: Vec<i32>) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];
    if nums.len() < 1 {
        return ret;
    }

    for e in nums {
        let mut d = e;
        let mut t:Vec<i32> = vec![];
        while d != 0 {
            t.push(d % 10);
            d /= 10;
        }
        t.reverse();
        ret.append(&mut t);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = separate_digits(vec![13,25,83,77]);
        assert_eq!(ret, vec![1,3,2,5,8,3,7,7]);

        let ret = separate_digits(vec![7,1,3,9]);
        assert_eq!(ret, vec![7,1,3,9]);
    }
}