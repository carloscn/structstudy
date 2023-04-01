
pub fn min_deletion_size(strs: Vec<String>) -> i32
{
    let depth = strs.len();
    let mut in_vec:Vec<char> = vec![];

    if depth < 1 {
        return 0;
    }

    let len = strs[0].len();

    for i in 0..depth {
        let mut temp:Vec<char> = strs[i].chars().into_iter().collect();
        in_vec.append(&mut temp);
    }

    for i in 0..len {
        for j in 0..(depth - 1) {
            if in_vec[j * len + i] > in_vec[(j + 1) * len + i] {
                return i as i32;
            }
        }
    }

    return 0;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let a = vec!["cba".to_string(), "daf".to_string(), "ghi".to_string()];
        assert_eq!(min_deletion_size(a), 1);
    }

    #[test]
    fn test_2() {
        let a = vec!["a".to_string(), "b".to_string()];
        assert_eq!(min_deletion_size(a), 0);
    }
}