
pub fn cells_in_range(s: &str) -> Vec<String>
{
    let mut ret:Vec<String> = vec![];

    if s.is_empty() {
        return ret;
    }

    let in_str:Vec<char> = s.chars().collect();
    let (z, x, z_d, x_d) =
        (in_str[0], in_str[3], in_str[1], in_str[4]);
    let mut j:u8;
    let mut i:u8 = z as u8;
    let mut t:Vec<char> = vec![];
    while i <= x as u8 {
        t.push(i as char);
        j = z_d as u8;
        while j <= (x_d as u8) {
            t.push(j as char);
            ret.push(t.iter().collect());
            t.pop();
            j += 1;
        }
        t.pop();
        i += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = cells_in_range("K1:L2");
        assert_eq!(ret, vec!["K1".to_string(),"K2".to_string(),"L1".to_string(),"L2".to_string()]);
        let ret = cells_in_range("A1:F1");
        assert_eq!(ret, vec!["A1".to_string(),"B1".to_string(),"C1".to_string(),"D1".to_string(),"E1".to_string(),"F1".to_string()]);
    }
}