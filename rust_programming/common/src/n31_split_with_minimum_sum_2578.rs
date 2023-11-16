
pub fn split_num(num: i32) -> i32
{
    let mut ret:i32 = 0;
    if num < 10 {
        return ret;
    }

    let mut num_dup = num;
    let mut nums_vec:Vec<i32> = vec![];
    while num_dup != 0 {
        nums_vec.push(num_dup % 10);
        num_dup /= 10;
    }
    nums_vec.sort();
    nums_vec.reverse();

    let mut a:i32 = 0;
    let mut b:i32 = 0;
    let mut i:usize = 0;
    while !nums_vec.is_empty() {
        let e = nums_vec.pop().unwrap();
        if (i & 0x1) == 0 {
            a += e;
            a *= 10;
        } else {
            b += e;
            b *= 10;
        }
        i += 1;
    }

    ret = a / 10 + b / 10;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_demo() {
        let ret = split_num(4325);
        assert_eq!(ret, 59);
        let ret = split_num(687);
        assert_eq!(ret, 75);
    }
}