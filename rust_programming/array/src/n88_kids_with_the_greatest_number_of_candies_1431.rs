
pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool>
{
    if candies.is_empty() {
        return vec![];
    }

    let mut ret:Vec<bool> = vec![];
    let mut max_candies:i32 = 0;

    for e in &candies {
        if *e > max_candies {
            max_candies = *e;
        }
    }

    for e in &candies {
        if *e + extra_candies >= max_candies {
            ret.push(true);
        } else {
            ret.push(false);
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = kids_with_candies(vec![2,3,5,1,3], 3);
        assert_eq!(ret, vec![true,true,true,false,true]);
        let ret = kids_with_candies(vec![4,2,1,1,2], 1);
        assert_eq!(ret, vec![true,false,false,false,false]);
        let ret = kids_with_candies(vec![12,1,12], 1);
        assert_eq!(ret, vec![true,false,true]);
    }
}