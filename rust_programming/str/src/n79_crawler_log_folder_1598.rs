
pub fn min_operations(logs: Vec<&str>) -> i32
{
    if logs.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;

    for e in &logs {
        if *e == "./" {
            continue;
        } else if *e == "../" {
            if ret != 0 {
                ret -= 1;
            }
            continue;
        }
        ret += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = min_operations(vec!["d1/","d2/","../","d21/","./"]);
        assert_eq!(ret, 2);
        let ret = min_operations(vec!["d1/","d2/","./","d3/","../","d31/"]);
        assert_eq!(ret, 3);
        let ret = min_operations(vec!["d1/","../","../","../"]);
        assert_eq!(ret, 0);
    }
}