
fn is_swap(a:i32, b:i32, rule:&Vec<i32>) -> bool
{
    if rule.len() < 1 || a == b {
        return false;
    }
    let a_pos = rule.iter().position(|&x| x == a);
    let b_pos = rule.iter().position(|&x| x == b);

    if a_pos == None && b_pos != None {
        return true;
    } else if a_pos != None && b_pos == None {
        return false;
    } else if a_pos != None && b_pos != None {
        return a_pos > b_pos;
    }

    return a > b;
}

pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32>
{
    let mut ret_vec:Vec<i32> = vec![];

    if arr1.len() < 1 ||
       arr2.len() < 2 ||
       arr1.len() < arr2.len() {
        return ret_vec;
    }

    if arr1.len() == 1 {
        ret_vec.push(arr1[0]);
        return ret_vec;
    }

    ret_vec.append(&mut arr1.clone());
    for i in 0..(arr1.len() - 1) {
        for j in 0..(arr1.len() - 1 - i) {
            if is_swap(ret_vec[j], ret_vec[j + 1], &arr2) {
                let temp = ret_vec[j + 1];
                ret_vec[j + 1] = ret_vec[j];
                ret_vec[j] = temp;
            }
        }
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let mut arr1 = vec![2,3,1,3,2,4,6,7,9,2,19];
        let mut arr2 = vec![2,1,4,3,9,6];
        let mut ret = relative_sort_array(arr1, arr2);
        assert_eq!(ret, vec![2,2,2,1,4,3,3,9,6,7,19]);
    }

    #[test]
    fn test_demo_1() {
        let mut arr1 = vec![28,6,22,8,44,17];
        let mut arr2 = vec![22,28,8,6];
        let mut ret = relative_sort_array(arr1, arr2);
        assert_eq!(ret, vec![22,28,8,6,17,44]);
    }
}