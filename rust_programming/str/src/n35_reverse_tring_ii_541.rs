

fn reverse_string_ii(in_str: &mut str, k: i32) -> i32
{
    //let mut dup_str = String::from(in_str);
    let str_len : usize = in_str.len();
    let delta : usize = 2 * k as usize;
    let mut ret = 0;
    let mut i : usize  = 0;
    let uk : usize = k as usize;

    if (0 == str_len) || (k <= 0)  {
        println!("input the parameters are failed!");
        return 0;
    }

    while i < str_len {
        i += delta;
        if 2*str_len - i < uk + str_len {
            ret = utils::str::reverse_region(in_str, i, str_len);
        } else {
            ret = utils::str::reverse_region(in_str, i - delta, i - delta + 1);
        }
        if 0 != ret {
            println!("failed on reverse region!");
            return -1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_reverse_string_ii()
    {
        let mut s = "abcdefg".to_string();
        let _ret = reverse_string_ii(&mut s, 2);

        println!("the result is {s}");
    }
}