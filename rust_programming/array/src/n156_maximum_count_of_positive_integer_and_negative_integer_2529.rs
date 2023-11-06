
pub fn maximum_count(nums: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if nums.len() < 1 {
        return ret;
    }

    let mut i:usize = nums.len() / 2;
    let mut neg_flag:bool = nums[i] < 0;
    while (i < nums.len()) || (i > 0) {
        if nums[i] < 0 {
            if neg_flag == false {
                break;
            }
            i += 1;
            neg_flag = true;
        } else if nums[i] > 0 {
            if neg_flag == true {
                break;
            }
            if i != 0 {
                i -= 1;
            } else {
                break;
            }
            neg_flag = false;
        } else {
            let mut j = i;
            while i < nums.len() {
                j += 1;
                if nums[j] > 0 {
                    break;
                }
            }
            if j != i {
                break;
            }
            j = i;
            while j > 0 {
                j -= 1;
                if nums[j] < 0 {
                    break;
                }
            }
            if j != i {
                break;
            }
        }
    }

    if i == 0 || i == nums.len() {
        return nums.len() as i32;
    }
    ret = i.max(nums.len() - i) as i32 - 1;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = maximum_count(vec![-2,-1,-1,1,2,3]);
        assert_eq!(ret, 3);

        let ret = maximum_count(vec![-3,-2,-1,0,0,1,2]);
        assert_eq!(ret, 3);

        let ret = maximum_count(vec![5,20,66,1314]);
        assert_eq!(ret, 4);
    }
}