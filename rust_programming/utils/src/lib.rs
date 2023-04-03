pub mod stack;
pub mod queue;
pub mod linked_list;

pub mod num {
    pub fn max<T:std::cmp::PartialOrd>(n:T, m:T) -> T {
        if n > m {
            return n;
        } else {
            return m;
        }
    }

    pub fn cmp<T:std::cmp::PartialOrd>(a:bool, n:T, m:T) -> T {
        if a {
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

    pub fn count_demical_field_number<T: std::ops::DivAssign<i32> + std::cmp::PartialEq<i32>>(n:T) -> usize {
        let mut ret:usize = 0;
        let mut t_n = n;

        while t_n != 0 {
            t_n /= 10;
            ret += 1;
        }

        return ret;
    }

}

pub mod str {
    use std::str::Bytes;
    use crate::num::swap_u8;
    use core::str::Chars;

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

    pub fn filter_letter(in_str:&mut String) {
        let in_chars = in_str.chars();
        let filter_str:String =
            in_chars.into_iter().filter(|e| ((*e >= 'a' && *e <= 'z') ||
                                             (*e >= 'A' && *e <= 'Z'))).collect();
        *in_str = format!("{}", filter_str);
    }

    pub fn to_lowercase(in_str: & mut String) {
        let f_str:String = String::from(in_str.to_lowercase());
        *in_str = format!("{f_str}");
    }

    pub fn to_uppercase(in_str:&mut String) {
        let f_str:String = String::from(in_str.to_uppercase());
        *in_str = format!("{f_str}");
    }

    pub fn sort_by_ascend(in_str:&mut String) {
        let in_chars:Chars = in_str.chars();
        let mut in_vect:Vec<char> = in_chars.into_iter().collect();
        in_vect.sort_by(|a, b| a.partial_cmp(b).unwrap());
        *in_str = format!("{}", in_vect.iter().collect::<String>());
    }

    pub fn sort_by_descend(in_str:&mut String) {
        let in_chars:Chars = in_str.chars();
        let mut in_vect:Vec<char> = in_chars.into_iter().collect();
        in_vect.sort_by(|a, b| b.partial_cmp(a).unwrap());
        *in_str = format!("{}", in_vect.iter().collect::<String>());
    }

    pub fn is_contains_repeat_element(a:&String, e:char) -> bool {
        let v_in:Vec<char> = a.chars().collect();
        let mut i:usize = 0;
        let mut count:usize = 0;

        while i < v_in.len() {
            if v_in[i] == e {
                count += 1;
                if (count == 2) {
                    return true;
                }
            }
            i += 1;
        }

        return false;
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

pub mod linklist {
    use crate::linked_list::*;

    pub fn show_i32_list(list: &List<i32>) {

        let mut iter = list.show();
        print!("List: ");
        while let Some(node) = iter.next() {
            print!("[{:?}]->", node);
        }
        println!("[None]");
    }
}

pub mod vec {
    use std::hash::Hash;
    use std::collections::HashSet;

    pub fn dedup<T: Eq + Hash + Copy>(v: &mut Vec<T>) { // note the Copy constraint
        let mut uniques = HashSet::new();
        v.retain(|e| uniques.insert(*e));
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::linked_list::*;

    #[test]
    fn test_filter_letter() {
        let mut my_str:String = String::from("123412345abcd1234ABCD1234");
        str::filter_letter(&mut my_str);
        assert_eq!(my_str, "abcdABCD".to_string());
    }

    #[test]
    fn test_to_lowercase() {
        let mut my_str:String = String::from("123412345abcd1234ABCD1234");
        str::to_lowercase(&mut my_str);
        assert_eq!(my_str, "123412345abcd1234abcd1234".to_string());
    }

    #[test]
    fn test_to_uppercase() {
        let mut my_str:String = String::from("123412345abcd1234ABCD1234");
        str::to_uppercase(&mut my_str);
        assert_eq!(my_str, "123412345ABCD1234ABCD1234".to_string());
    }

    #[test]
    fn test_sort_by_ascend() {
        let mut my_str:String = String::from("abcgdef");
        str::sort_by_ascend(&mut my_str);
        assert_eq!(my_str, "abcdefg".to_string());
    }

    #[test]
    fn test_sort_by_descend() {
        let mut my_str:String = String::from("abcgdef");
        str::sort_by_descend(&mut my_str);
        assert_eq!(my_str, "gfedcba".to_string());
    }

    #[test]
    fn test_link_list_show() {
        let mut list = List::new();
        list.push(1);
        list.push(2);
        list.push(3);
        linklist::show_i32_list(&list);
    }
}