
pub fn count_points(rings: &str) -> i32
{
    let mut ret:i32 = 0;

    if rings.len() < 1 {
        return ret;
    }

    let mut i:usize = 0;
    let mut label:Vec<Vec<char>> = vec![vec![]; 10];
    let ring_color_vec:Vec<char> = rings.chars()
                                        .filter(|x| x.is_alphabetic())
                                        .collect();
    let ring_label_vec:Vec<char> = rings.chars()
                                        .filter(|x| x.is_numeric())
                                        .collect();
    while i < ring_color_vec.len() {
        label[(ring_label_vec[i] as u8 - '0' as u8) as usize].push(ring_color_vec[i]);
        i += 1;
    }

    for e in label {
        if e.contains(&'B') && e.contains(&'G') && e.contains(&'R') {
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
        let ret = count_points("B0B6G0R6R0R6G9");
        assert_eq!(ret, 1);
        let ret = count_points("B0R0G0R9R0B0G0");
        assert_eq!(ret, 1);
        let ret = count_points("G4");
        assert_eq!(ret, 0);
    }
}