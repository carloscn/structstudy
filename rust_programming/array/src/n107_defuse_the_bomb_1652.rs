
pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![0; code.len()];

    if code.len() < 1 || k == 0 {
        return ret;
    }

    for i in 0..code.len() {
        for j in 0..i32::abs(k) as usize {
            let pos:usize;
            if k > 0 {
                pos = (i + j + 1) % code.len();
            } else {
                pos = (i + code.len() - j - 1) % code.len();
            }
            ret[i] += code[pos];
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let mut ret = decrypt(vec![5,7,1,4], 3);
        assert_eq!(ret, vec![12,10,16,13]);
        let mut ret = decrypt(vec![2,4,9,3], -2);
        assert_eq!(ret, vec![12,5,6,13]);
        let mut ret = decrypt(vec! [1,2,3,4], 0);
        assert_eq!(ret, vec![0,0,0,0]);
    }
}