
pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32
{
    if arr.len() < 1 {
        return 0;
    }

    let mut i:usize;
    let mut j:usize;
    let mut k:usize;
    let mut n:usize;
    let mut ret:i32 = 0;
    let mut temp_buffer:Vec<i32> = vec![0; arr.len()];
    let mut ones_format:Vec<usize> = vec![];
    let mut ones_bit_count:usize = 1;

    while ones_bit_count <= arr.len() {
        let mut t = 0;
        i = 0;
        while i < ones_bit_count {
            t = t << 1 | 1;
            i += 1;
        }

        i = 0;
        while i + ones_bit_count - 1 < arr.len() {
            ones_format.push(t << i);
            i += 1;
        }

        ones_bit_count += 2;
    }

    for e in ones_format {
        j = e; k = 0; n = 0;
        while j != 0 {
            if j & 0x1 == 0x1 {
                temp_buffer[n] = arr[k];
                n += 1;
            }
            j >>= 1;
            k += 1;
        }

        for m in 0..n {
            ret += temp_buffer[m];
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = sum_odd_length_subarrays(vec![1,4,2,5,3]);
        assert_eq!(ret, 58);
        let ret = sum_odd_length_subarrays(vec![1,2]);
        assert_eq!(ret, 3);
        let ret = sum_odd_length_subarrays(vec![10,11,12]);
        assert_eq!(ret, 66);
    }
}