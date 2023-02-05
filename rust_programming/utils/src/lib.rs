
pub fn utils_max(n:u64, m:u64) -> u64
{
    if n > m {
        return n;
    } else {
        return m;
    }
}

pub fn utils_is_capital(c : char) -> bool
{
    let mut ret = false;

    if (c >= 'A') && (c <= 'Z') {
        ret = true;
    }

    return ret;
}

pub fn utils_is_lowercase(c : char) -> bool
{
    let mut ret = false;

    if (c >= 'a') && (c <= 'z') {
        ret = true;
    }

    return ret;
}

pub fn utils_swap_u8(a :&mut u8, b: &mut u8)
{
    if *a == *b {
        return;
    }
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

pub fn utils_swap_pos_in_str(in_str: &mut str, a: usize, b: usize) -> i32
{
    let mut ret : i32 = 0;
    let len = in_str.len();

    if (a > len) || (b > len) {
        ret = -1;
        return ret;
    }

    unsafe {
        let bytes : &mut [u8] = in_str.as_bytes_mut();
        let t : u8 = bytes[a];
        bytes[a] = bytes[b];
        bytes[b] = t;
    }

    return ret;
}

pub fn utils_str_reverse_region(in_str: &mut str, start : usize, end : usize) -> i32
{
    let mut ret : i32 = 0;
    let mut count: usize = 1;
    let len: usize = in_str.len();
    if start == end {
        return ret;
    }

    if (start > end) || (len == 0) {
        return ret;
    }

    if end - start == 1 {
        ret = utils_swap_pos_in_str(in_str, start, end);
        if ret != 0 {
            return ret;
        }
    }

    let mut j = start;
    while j < (end - start) / 2 {
        ret = utils_swap_pos_in_str(in_str, j, end - count);
        if ret != 0 {
             return ret;
        }
        count += 1;
        j += 1;
    }

    return ret;
}

pub fn utils_str_reverse(in_str: &mut str) -> i32
{
    return utils_str_reverse_region(in_str, 0, in_str.len());
}

// pub fn utils_strcpy(dest : &mut str, src : &str) -> i32
// {
//     let mut ret = 0i32;

//     if dest.len() < src.len() {
//         ret = -1;
//         return ret;
//     }

//     unsafe {
//         let dest_bytes : &mut [u8] = dest.as_bytes_mut();
//         let src_bytes : &mut [u8] = src.as_bytes_mut();
//         for i in [0..src.len()] {
//             dest_bytes[i] = src_bytes[i];
//         }
//     }
//     return ret;
// }