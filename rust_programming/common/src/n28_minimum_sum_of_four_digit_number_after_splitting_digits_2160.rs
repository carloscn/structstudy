
pub fn minimum_sum(num: i32) -> i32
{
    let ret:i32;
    let mut num_dup = num;
    let mut pos:Vec<i32> = vec![];

    while num_dup != 0 {
        pos.push(num_dup %10 as i32);
        num_dup /= 10;
    }

    pos.sort();
    pos.reverse();

    let mut i:usize = 0;
    let mut new1:i32 = 0;
    let mut new2:i32 = 0;
    let mut j1:i32 = 0;
    let mut j2:i32 = 0;
    while i < pos.len() {
        if i & 0x1 == 0 {
            new1 += pos[i] * i32::pow(10, j1 as u32);
            j1 += 1;
        } else {
            new2 += pos[i] * i32::pow(10, j2 as u32);
            j2 += 1;
        }
        i += 1;
    }

    ret = new1 + new2;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_demo() {
        let ret = minimum_sum(2932);
        assert_eq!(ret, 52);
        let ret = minimum_sum(4009);
        assert_eq!(ret, 13);
    }
}