fn longest_uncommon_subseq(str_1: &str, str_2: &str, out: &mut i32) -> i32
{
    let ret: i32 = 0;
    let sl_a: i32 = str_1.len() as i32;
    let sl_b: i32 = str_2.len() as i32;

    if str_1 == str_2 {
        *out = -1;
        return ret;
    }

    if sl_a >= sl_b {
        *out = sl_a;
    } else {
        *out = sl_b;
    }

    return ret;
}

pub fn test_longest_uncommon_subseq() {
    let mut ret: i32 = 0;
    let mut len: i32 = 0;
    ret = longest_uncommon_subseq("aaa", "bbb", &mut len);
    if 0 != ret {
        println!("failed on longest_uncommon_subseq!");
        return;
    }
    println!("the result is {len}.");
}