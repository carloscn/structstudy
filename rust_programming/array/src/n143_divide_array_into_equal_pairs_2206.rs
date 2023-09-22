
pub fn divide_array(nums: Vec<i32>) -> bool
{
    if nums.len() < 1 {
        return false;
    }

    let mut out_buffer:Vec<i32> = vec![];
    let mut in_buffer:Vec<i32> = nums.clone();

    in_buffer.sort();

    for e in in_buffer {
        if out_buffer.is_empty() {
            out_buffer.push(e);
            continue;
        }

        if out_buffer[out_buffer.len() - 1] == e {
            out_buffer.pop();
        }
    }

    return out_buffer.is_empty();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = divide_array(vec![3,2,3,2,2,2]);
        assert_eq!(ret, true);

        let ret = divide_array(vec![1,2,3,4]);
        assert_eq!(ret, false);
    }
}