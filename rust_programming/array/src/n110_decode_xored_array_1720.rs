
pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32>
{
    if encoded.len() < 1 {
        return encoded;
    }

    let mut ret:Vec<i32> = vec![];

    ret.push(first);

    for i in 0..encoded.len() {
        ret.push(ret[i] ^ encoded[i]);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = decode(vec![1,2,3], 1);
        assert_eq!(ret, vec![1,0,2,1]);
        let ret = decode(vec![6,2,7,3], 4);
        assert_eq!(ret, vec![4,2,0,7,4]);
    }
}