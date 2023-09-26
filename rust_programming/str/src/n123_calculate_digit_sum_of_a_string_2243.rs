
fn round_up(N:i32, S:i32) -> i32
{
    return (((N) + (S) - 1) / (S)) * (S) - N;
}

fn string_sum(s:&Vec<char>, k: i32) -> Vec<char>
{
    let mut i:usize = 0;
    let mut t:Vec<char> = vec![];
    let mut sd: Vec<char> = s.clone();
    let len = round_up(sd.len() as i32, k);

    for _j in 0..len {
        sd.push('0');
    }

    while i < sd.len() {
        let mut sum:i32 = 0;
        for j in 0..k as usize {
            sum += (sd[i + j] as u8 - '0' as u8) as i32;
        }
        i += k as usize;
        if sum >= 10 {
            while sum != 0 {
                t.insert(0, ((sum % 10) as u8 + '0' as u8) as char);
                sum /= 10;
            }
        } else {
            t.push((sum as u8 + '0' as u8) as char);
        }
    }

    return t;
}

pub fn digit_sum(s: &str, k: i32) -> String
{
    if s.len() < 1 {
        return String::new();
    }

    let mut s_vec:Vec<char> = s.chars().collect();

    while s_vec.len() > k as usize {
        s_vec = string_sum(&s_vec, k);
    }

    return s_vec.iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = digit_sum("11111222223", 3);
        assert_eq!(ret, "135".to_string());
        let ret = digit_sum("00000000", 3);
        assert_eq!(ret, "000".to_string());
    }
}