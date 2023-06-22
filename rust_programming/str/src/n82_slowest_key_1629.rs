
pub fn slowest_key(release_times: Vec<i32>, keys_pressed: &str) -> char
{
    if release_times.is_empty() ||
       release_times.len() != keys_pressed.len() {
        return '\0';
    }

    let mut ret:char = '\0';
    let mut max_time:i32 = i32::MIN;
    let keys_vec:Vec<char> = keys_pressed.chars().collect();

    for i in 1..release_times.len() {
        let e = release_times[i] - release_times[i - 1];
        if e > max_time {
            max_time = e;
            ret = keys_vec[i];
        } else if e == max_time && keys_vec[i] > ret {
            ret = keys_vec[i];
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = slowest_key(vec![9,29,49,50], "cbcd");
        assert_eq!(ret, 'c');
        let ret = slowest_key(vec![12,23,36,46,62], "spuda");
        assert_eq!(ret, 'a');
    }
}