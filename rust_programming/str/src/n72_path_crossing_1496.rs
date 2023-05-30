
pub fn is_path_crossing(path: String) -> bool
{
    if path.len() < 1 {
        return false;
    }

    let mut point:(i32, i32) = (0,0);
    let path_vec:Vec<char> = path.chars().collect();

    for e in path_vec {
        if e == 'N' || e == 'n' {
            point.1 += 1;
        } else if e == 'S' || e == 's' {
            point.1 -= 1;
        } else if e == 'W' || e == 'w' {
            point.0 -= 1;
        } else if e == 'E' || e == 'e' {
            point.0 += 1;
        } else {
            return false;
        }

        if (0, 0) == point  {
            return true;
        }
    }

    return false;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = is_path_crossing("NES".to_string());
        assert_eq!(ret, false);
        let ret = is_path_crossing("NESWW".to_string());
        assert_eq!(ret, true);
    }
}