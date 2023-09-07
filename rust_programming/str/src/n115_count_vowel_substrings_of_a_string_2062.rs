
fn is_vowel(c:char) -> bool
{
    if c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' {
        return true;
    }

    return false;
}

fn is_contiguous(w:&Vec<char>, start:usize, end:usize) -> bool
{
    let copied_slice = &w[start..=end];
    let mut a_f:bool = false;
    let mut e_f:bool = false;
    let mut i_f:bool = false;
    let mut o_f:bool = false;
    let mut u_f:bool = false;

    for e in copied_slice {
        if *e == 'a' {
            a_f = true;
        } else if *e == 'e' {
            e_f = true;
        } else if *e == 'i' {
            i_f = true;
        } else if *e == 'o' {
            o_f = true;
        } else if *e == 'u' {
            u_f = true;
        } else {
            return false;
        }
    }

    return a_f && e_f && i_f && o_f && u_f;
}

pub fn count_vowel_substrings(word: &str) -> i32
{
    let mut ret:i32 = 0;

    if word.len() < 5 {
        return ret;
    }

    let w_v:Vec<char> = word.chars().collect();
    for i in 0..w_v.len() - 4 {
        let mut contiguous_count = 0_i32;
        for j in i..w_v.len() {
            if is_vowel(w_v[j]) {
                contiguous_count += 1;
            } else {
                contiguous_count = 0;
            }
            if contiguous_count >= 5 {
                if is_contiguous(&w_v, i, j) {
                    ret += 1;
                }
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = count_vowel_substrings("aeiouu");
        assert_eq!(ret, 2);
        let ret = count_vowel_substrings("unicornarihan");
        assert_eq!(ret, 0);
        let ret = count_vowel_substrings("cuaieuouac");
        assert_eq!(ret, 7);
    }
}