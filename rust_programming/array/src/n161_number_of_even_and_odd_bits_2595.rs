
pub fn even_odd_bit(n: i32) -> Vec<i32>
{
    let mut d:i32 = n;
    let mut i:usize = 0;
    let mut ret:Vec<i32> = vec![0, 0];

    while d != 0 {
        if (d & 0x1) == 1 {
            ret[i & 0x1] += 1;
        }
        d >>= 1;
        i += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = even_odd_bit(17);
        assert_eq!(ret, vec![2, 0]);

        let ret = even_odd_bit(2);
        assert_eq!(ret, vec![0, 1]);
    }
}