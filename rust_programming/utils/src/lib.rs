
pub mod num {
    pub fn max(n:u64, m:u64) -> u64 {
        if n > m {
            return n;
        } else {
            return m;
        }
    }

    pub fn min(n:u64, m:u64) -> u64 {
        if n < m {
            return n;
        } else {
            return m;
        }
    }

    pub fn is_capital(c : char) -> bool {
        let mut ret = false;
        if (c >= 'A') && (c <= 'Z') {
            ret = true;
        }
        return ret;
    }

    pub fn is_lowercase(c : char) -> bool {
        let mut ret = false;

        if (c >= 'a') && (c <= 'z') {
            ret = true;
        }

        return ret;
    }

    pub fn swap_u8(a :&mut u8, b: &mut u8) {
        if *a == *b {
            return;
        }
        *a = (*a) ^ (*b);
        *b = (*b) ^ (*a);
        *a = (*a) ^ (*b);
    }

    pub fn swap_i64(a :&mut i64, b: &mut i64) {
        if *a == *b {
            return;
        }
        *a = (*a) ^ (*b);
        *b = (*b) ^ (*a);
        *a = (*a) ^ (*b);
    }

}

pub mod str {
    use std::str::Bytes;

    pub fn swap_pos(in_str: &mut str, a: usize, b: usize) -> i32 {
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

    pub fn reverse_region(in_str: &mut str, start : usize, end : usize) -> i32 {
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
            ret = swap_pos(in_str, start, end);
            if ret != 0 {
                return ret;
            }
        }
        let mut j = start;
        while j < (end - start) / 2 {
            ret = swap_pos(in_str, j, end - count);
            if ret != 0 {
                 return ret;
            }
            count += 1;
            j += 1;
        }
        return ret;
    }

    pub fn reverse(in_str: &mut str) -> i32 {
        return reverse_region(in_str, 0, in_str.len());
    }

    pub fn append_all_substr(in_str: &str) -> Vec<String> {
        let mut subs_vec:Vec<String> = Vec::new();
        let mut len:usize = 1;
        let in_len:usize = in_str.len();

        while len <= in_len {
            for start in 0..(in_len - len + 1) {
                let sub_str : String = String::from(&in_str[start..start + len]);
                subs_vec.push(sub_str);
            }
            len += 1;
        }

        return subs_vec;
    }

    pub fn conv_uppercase(c:u8) -> u8 {
        if c >= 'a' as u8 && c <= 'z' as u8 {
            return c - 32;
        } else {
            return c;
        }
    }

    pub fn conv_lowercase(c:u8) -> u8 {
        if c >= 'A' as u8 && c <= 'Z' as u8 {
            return c + 32;
        } else {
            return c;
        }
    }
}

pub mod array {
    pub fn sum_i64(array: &[i64], len: usize) -> i64 {
        let mut sum:i64 = 0;
        for val in array.iter() {
            sum += val;
        }
        return sum;
    }

    pub fn swap_i64(array :&mut [i64], i:usize, j:usize) {

        let a = array[i];
        let b = array[j];

        if a == b {
            return;
        }

        array[i] = b;
        array[j] = a;
    }
}
