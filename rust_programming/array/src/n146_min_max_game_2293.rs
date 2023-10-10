
pub fn min_max_game(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if nums.len() == 0 {
        return ret;
    }

    let mut array:Vec<i32> = nums.clone();

    while array.len() != 1 {
        let mut j:usize = 0;
        let mut i:usize = 1;
        let mut t_buf:Vec<i32> = vec![];
        while i < array.len() {
            let e:i32;
            if (j & 0x1) == 0 {
                e = array[i].min(array[i - 1]);
            } else {
                e = array[i].max(array[i - 1]);
            }
            t_buf.push(e);
            j += 1;
            i = 2 * i + 1;
        }
        array = t_buf;
    }

    ret = array[0];

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = min_max_game(vec![1,3,5,2,4,8,2,2]);
        assert_eq!(ret, 1);

        let ret = min_max_game(vec![3]);
        assert_eq!(ret, 3);
    }
}