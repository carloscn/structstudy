
fn count_bit_1(num:i32) -> i32
{
    let mut e = num;
    let mut ret:i32 = 0;

    while e != 0 {
        if e & 1 == 1 {
            ret += 1;
        }
        e >>= 1;
    }

    return ret;
}

pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32>
{
    if arr.len() < 1 {
        return arr;
    }

    let mut ret:Vec<i32> = arr.clone();

    for i in 0..ret.len() {
        for j in 0..(ret.len() - i - 1) {
            let count_a = count_bit_1(ret[j]);
            let count_b = count_bit_1(ret[j + 1]);
            if (count_a > count_b) ||
               ((count_a == count_b) && (ret[j] > ret[j + 1])) {
                ret[j] ^= ret[j+1];
                ret[j+1] ^= ret[j];
                ret[j] ^= ret[j+1];
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = sort_by_bits(vec![0,1,2,3,4,5,6,7,8]);
        assert_eq!(ret, vec![0,1,2,4,8,3,5,6,7]);
        let ret = sort_by_bits(vec![1024,512,256,128,64,32,16,8,4,2,1]);
        assert_eq!(ret, vec![1,2,4,8,16,32,64,128,256,512,1024]);
        let ret = sort_by_bits(vec![10000,10000]);
        assert_eq!(ret, vec![10000,10000]);
        let ret = sort_by_bits(vec![2,3,5,7,11,13,17,19]);
        assert_eq!(ret, vec![2,3,5,17,7,11,13,19]);
        let ret = sort_by_bits(vec![10,1000,100,10000]);
        assert_eq!(ret, vec![10,100,10000,1000]);
    }
}