use core::num;
use std::vec;

pub fn distribute_candies(candies: i32, num_people: i32) -> Vec<i32>
{
    let mut ret_vec:Vec<i32> = vec![0; num_people as usize];

    if 0 == candies || 0 == num_people {
        return ret_vec;
    }

    let mut i:usize = 0;
    let mut n:i32 = 1;
    let mut candies_dup = candies;

    while 0 != candies_dup {
        if candies_dup < n {
            n = candies_dup;
        }
        ret_vec[i] += n;
        candies_dup -= n;
        n += 1;
        i = (i + 1) % (num_people as usize);
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = distribute_candies(7, 4);
        assert_eq!(ret, vec![1,2,3,1]);
    }

    #[cfg(test)]
    mod tests {
        use super::*;

        #[test]
        fn test_1() {
            assert_eq!(distribute_candies(7, 4), vec![1, 2, 3, 1]);
        }

        #[test]
        fn test_2() {
            assert_eq!(distribute_candies(10, 3), vec![5, 2, 3]);
        }

        #[test]
        fn test_3() {
            assert_eq!(distribute_candies(0, 5), vec![0, 0, 0, 0, 0]);
        }

        #[test]
        fn test_4() {
            assert_eq!(distribute_candies(1, 1), vec![1]);
        }

        #[test]
        fn test_5() {
            assert_eq!(distribute_candies(1000000000, 1), vec![1000000000]);
        }

        #[test]
        fn test_6() {
            assert_eq!(distribute_candies(8, 1), vec![8]);
        }
    }
}