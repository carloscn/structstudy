
fn count_one_bits(num:usize) -> usize
{
    let mut count:usize = 0;
    let mut input:usize = num;

    while input != 0 {
        input &= input - 1;
        count += 1;
    }

    return count;
}

pub fn count_good_substrings(s: &str) -> i32
{
    if s.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;
    let mut s_v:Vec<char> = s.chars().collect();
    let (mut i, mut j, mut k, mut num, mut n) =
        (0usize, 3usize, 0usize, (1 << s.len()) as usize, 0usize);

    for n in 0..num {
        if count_one_bits(n) != 3 {
            continue;
        }

        j = n;
        k = 0;
        i = 0;
        let mut t_buf:Vec<char> = vec!['0'; 3];
        while j != 0 {
            if j & 1 == 1 {
                t_buf[i] = s_v[k];
                i += 1;
            }
            j >>= 1;
            k += 1;
        }
        t_buf.sort();
        t_buf.dedup();
        if t_buf.len() == 3 {
            println!("the result is {:?}\n", t_buf);
            ret += 1;
        }

    }
    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = count_good_substrings("xyzzaz");
        assert_eq!(ret, 10);
        let ret = count_good_substrings("aababcabc");
        assert_eq!(ret, 24);
    }
}