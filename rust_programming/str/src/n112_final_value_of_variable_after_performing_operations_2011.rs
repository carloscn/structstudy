
fn conv_str_to_int(in_str:&str) -> i32
{
    if in_str == "++X" || in_str == "X++" {
        return 1;
    } else if in_str == "--X" || in_str == "X--" {
        return -1;
    } else {
        return 0;
    }
}

pub fn final_value_after_operations(operations: Vec<&str>) -> i32
{
    if operations.len() < 1 {
        return 0;
    }

    let mut ret:i32 = 0;

    for e in operations {
        ret += conv_str_to_int(e);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = final_value_after_operations(vec!["--X","X++","X++"]);
        assert_eq!(ret, 1);
        let ret = final_value_after_operations(vec!["++X","++X","X++"]);
        assert_eq!(ret, 3);
        let ret = final_value_after_operations(vec!["X++","++X","--X","X--"]);
        assert_eq!(ret, 0);
    }
}