
use rand::Rng;

pub fn get_no_zero_integers(n: i32) -> Vec<i32>
{
    let mut ret:Vec<i32> = vec![];

    if n < 2 {
        return ret;
    }
    let mut rng_ctx = rand::thread_rng();
    let mut rand = 1;
    let mut left = n - rand;

    while rand.to_string().contains("0") || left.to_string().contains("0") {
        rand = rng_ctx.gen_range(2..n-1);
        left = n - rand;
    }

    ret.push(rand);
    ret.push(left);

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashSet;

    fn test_pass(n:i32, array:Vec<i32>) -> bool
    {
        if array.len() != 2 {

            return 0 == array.len();
        }

        let mut sum = 0;
        for e in array {
            sum += e;
            if e.to_string().contains("0") {
                println!("the {e} contain 0");
                return false;
            }
        }

        if sum == n {
            return true;
        } else {
            println!("the {sum} != {n}");
            return false;
        }
    }

    #[test]
    fn test_demo() {
        assert!(test_pass(11, get_no_zero_integers(11)));
    }

    #[test]
    fn test_get_no_zero_integers() {
        let test_cases = [
            (2, vec![1, 1]),
            (11, vec![2, 9]),
            (10000, vec![1, 9999]),
            (69, vec![1, 68]),
            (1010, vec![11, 999]),
            (0, vec![1, -1]),
            (20, vec![2, 18]),
            (100000, vec![1, 99999]),
        ];

        for (n, expected) in test_cases {
            assert!(test_pass(n, get_no_zero_integers(n)));
        }
    }
}