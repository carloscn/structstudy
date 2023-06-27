
fn array_contain(arr: &Vec<i32>, pic: &Vec<i32>) -> bool
{
    if pic.len() > arr.len() {
        return false;
    } else if pic.len() == arr.len() {
        return *pic == *arr;
    }

    for i in 0..arr.len() - pic.len() + 1 {
        for j in 0..pic.len() {
            if arr[i + j] == pic[j] {
                return true;
            }
        }
    }

    return false;
}

pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool
{
    if arr.len() < 1 || pieces.len() < 1 {
        return false;
    }

    for e in &pieces {
        if array_contain(&arr, e) == false {
            return false;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = can_form_array(vec![15,88], vec![vec![88], vec![15]]);
        assert_eq!(ret, true);
        let ret = can_form_array(vec![49,18,16], vec![vec![16,18,49]]);
        assert_eq!(ret, false);
        let ret = can_form_array(vec![91,4,64,78], vec![vec![78],vec![4,64],vec![91]]);
        assert_eq!(ret, true);
    }
}