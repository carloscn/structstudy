
fn find_first(array:&Vec<i32>, target:i32) -> Vec<i32>
{
    let mut ret_vec:Vec<i32> = vec![-1, -1];
    let mut left:usize = 0;
    let mut right:usize = array.len() - 1;
    let mut mid:usize = left + (right - left) / 2;

    while left <= right {
        if array[mid] < target {
            left = mid;
        } else if array[mid] > target {
            right = mid;
        } else {
            break;
        }
        mid = left + (right - left) / 2;
    }
    
    if (mid == 0) || (mid == array.len() - 1) {
        return ret_vec;
    }

    right = mid;
    left = mid;
    let mut is_left:bool = false;
    let mut is_right:bool = false;
    while (is_left == false) || (is_right == false) {
        if array[mid] == array[left] {
            left -= 1;
        } else {
            ret_vec[0] = (left + 1) as i32;
            is_left = true;
        }

        if array[mid] == array[right] {
            right += 1;
        }  else {
            ret_vec[1] = (right - 1) as i32;
            is_right = true;
        }
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_shortest_distance() {
        let array:Vec<i32> = vec![5,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10];
        let target:i32 = 8;
        let ret = find_first(&array, target);

        assert_eq!(ret, vec![10, 16]);
    }
}