
pub fn is_covered(ranges: Vec<Vec<i32>>, left: i32, right: i32) -> bool
{
    if ranges.len() < 1 {
        return false;
    }

    let mut ret:bool = false;

    for e in &ranges {
        if left > e[1] || left > e[0] {
            continue;
        } else {
            ret = true;
            break;
        }
    }

    if ret == false {
        return false;
    }

    ret = false;
    for e in &ranges {
        if right > e[1] || right > e[0] {
            continue;
        } else {
            ret = true;
            break;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = is_covered(vec![vec![1,2],vec![3,4],vec![5,6]], 2, 5);
        assert_eq!(ret, true);
        let ret = is_covered(vec![vec![1,10], vec![10,20]], 21, 21);
        assert_eq!(ret, false);
    }
}