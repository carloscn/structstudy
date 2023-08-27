
fn caculate_min_distance(a:char, b:char) -> i32
{
    let a_u = a as i32;
    let b_u = b as i32;

    return i32::abs(a_u - b_u)
           .min(26 - i32::abs(a_u - b_u));
}

pub fn min_time_to_type(word: &str) -> i32
{
    if word.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;
    let mut w_v:Vec<char> = word.chars().collect();

    w_v.insert(0, 'a');

    for i in 0..w_v.len() - 1 {
        ret += caculate_min_distance(w_v[i], w_v[i + 1]);
    }

    return ret + w_v.len() as i32 - 1;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = min_time_to_type("abc");
        assert_eq!(ret, 5);
        let ret = min_time_to_type("bza");
        assert_eq!(ret, 7);
        let ret = min_time_to_type("zjpc");
        assert_eq!(ret, 34);
    }
}