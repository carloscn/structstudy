
pub fn add_to_array_form(num: Vec<i32>, k: i32) -> Vec<i32>
{
    if 0 == k {
        return num;
    }

    let mut k_t = k;
    let mut k_vec:Vec<i32> = vec![];
    while k_t != 0 {
        k_vec.insert(0,k_t % 10);
        k_t /= 10;
    }

    if num.len() == 0 {
        return k_vec;
    }

    let mut p_k:i32;
    let mut n_k:i32;
    let mut i:i32 = (k_vec.len() - 1) as i32;
    let mut j:i32 = (num.len() - 1) as i32;
    let mut prom:i32 = 0;
    let mut sum:i32;
    let mut ret_vec:Vec<i32> = vec![];

    while i != -1 || j != -1 {
        if i != -1 {
            p_k = k_vec[i as usize];
            i -= 1;
        } else {
            p_k = 0;
        }
        if j != -1 {
            n_k = num[j as usize];
            j -= 1;
        } else {
            n_k = 0;
        }

        sum = prom + p_k + n_k;
        ret_vec.insert(0, sum % 10);
        prom = sum / 10;
    }

    if prom != 0 {
        ret_vec.insert(0, prom);
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        // num = [1,2,0,0], k = 34
        let ret = add_to_array_form(vec![1,2,0,0], 34);
        assert_eq!(ret, vec![1,2,3,4]);
    }
    #[test]
    fn test_add_to_array_form() {
        // Test case 1: Normal input
        assert_eq!(add_to_array_form(vec![1, 2, 0, 0], 34), vec![1, 2, 3, 4]);

        // Test case 2: Input with carry
        assert_eq!(add_to_array_form(vec![2, 7, 4], 181), vec![4, 5, 5]);

        // Test case 3: Input with more digits in k
        assert_eq!(add_to_array_form(vec![9, 9, 9], 123), vec![1, 1, 2, 2]);

        // Test case 4: Input with more digits in num
        assert_eq!(add_to_array_form(vec![5, 6, 7], 123), vec![6, 9, 0]);

        // Test case 5: Input with all zeros
        assert_eq!(add_to_array_form(vec![0, 0, 0], 123), vec![1, 2, 3]);
    }
}