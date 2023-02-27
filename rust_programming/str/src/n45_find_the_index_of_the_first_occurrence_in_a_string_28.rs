

fn is_compare(in_str:&str, pat:&str, res:&mut bool) -> i32
{
    let mut in_chars = in_str.chars();
    let mut pat_chars = pat.chars();
    let mat_c:char = pat_chars.nth(0).unwrap();
    let mut i:i32 = 0;
    let mut mat_index:i32 = 0;

    *res = true;
    for e in pat_chars {
        if e == mat_c && 0 == mat_index {
            mat_index = i;
            if false == *res {
                return mat_index;
            }
        }
        if false == *res || e != in_chars.nth(i as usize).unwrap() {
            *res = false;
            if 0 == mat_index {
                continue;
            } else {
                return mat_index;
            }
        }
        i += 1;
    }

    return mat_index;
}

fn find_sub_str(in_str:&String, pat:&String) -> i32
{
    let mut mat_index:i32;
    let mut i:usize = 0;
    let in_len:usize = in_str.len();
    let mut res:bool = true;

    while i < in_len {
        mat_index = is_compare(&in_str[i..], &pat[0..], &mut res);
        if true == res {
            return i as i32 + mat_index;
        }
        if 0 == mat_index {
            i += 1;
        } else {
            i += mat_index as usize;
        }
    }

    mat_index = -1;

    return mat_index;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_most_common_word() {
        let ret:i32 = find_sub_str(&"adesaddadbutsad".to_string(), &"sad".to_string());
        assert_eq!(ret, 4);
    }
}