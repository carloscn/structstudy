
fn append_to_vec((v1, v2, v3) : (i32, i32, i32), vec:&mut Vec<i32>)
{
    let mut value:i32;

    if v3 & 0x01 != 1 {
        value = v1 * 100 + v2 * 10 + v3;
        if v1 != 0 && !vec.contains(&value) {
            vec.push(value);
        }
        value = v2 * 100 + v1 * 10 + v3;
        if v2 != 0 && !vec.contains(&value) {
            vec.push(value);
        }
    }
    if v2 & 0x01 != 1 {
        value = v1 * 100 + v3 * 10 + v2;
        if v1 != 0 && !vec.contains(&value) {
            vec.push(value);
        }
        value = v3 * 100 + v1 * 10 + v2;
        if v3 != 0 && !vec.contains(&value) {
            vec.push(value);
        }
    }
    if v1 & 0x01 != 1 {
        value = v2 * 100 + v3 * 10 + v1;
        if v2 != 0 && !vec.contains(&value) {
            vec.push(value);
        }
        value = v3 * 100 + v2 * 10 + v1;
        if v3 !=0 && !vec.contains(&value) {
            vec.push(value);
        }
    }
}

pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32>
{
    if digits.len() < 3 {
        return Vec::new();
    }

    let mut ret:Vec<i32> = vec![];

    for i in 0..digits.len() - 2 {
        for j in i + 1..digits.len() - 1 {
            for k in j + 1..digits.len() {
                append_to_vec((digits[i], digits[j], digits[k]), &mut ret);
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
        let mut res = vec![102,120,130,132,210,230,302,310,312,320];
        let mut ret = find_even_numbers(vec![2,1,3,0]);
        res.sort();
        ret.sort();
        assert_eq!(ret, res);

        let mut res = vec![222,228,282,288,822,828,882];
        let mut ret = find_even_numbers(vec![2,2,8,8,2]);
        res.sort();
        ret.sort();
        assert_eq!(ret, res);

        let mut res = vec![];
        let mut ret = find_even_numbers(vec![3,7,5]);
        res.sort();
        ret.sort();
        assert_eq!(ret, res);
    }
}