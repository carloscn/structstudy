
fn is_change(array:Vec<i32>) -> bool
{
    let mut five_pool:Vec<i32> = vec![];
    let mut ten_pool:Vec<i32> = vec![];

    for e in &array {
         match *e {
            5 => {
                five_pool.push(*e);
            },
            10 => {
                if five_pool.is_empty() {
                    return false;
                }
                five_pool.pop();
                ten_pool.push(*e);
            },
            20 => {
                if !ten_pool.is_empty() {
                    if five_pool.is_empty() {
                        return false;
                    }
                    ten_pool.pop();
                    five_pool.pop();
                } else {
                    if five_pool.len() < 3 {
                        return false;
                    }
                    for i in [0..2] {
                        five_pool.pop();
                    }
                }
            },
            _ => {
                return false;
            }
        }
    }
    return true;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_change() {
        assert_eq!(is_change(vec![5,5,5,10,20]), true);
        assert_eq!(is_change(vec![5,5,10,10,20]), false);
    }
}