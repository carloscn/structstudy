
fn valid_palindrome_ii(in_str:&str) -> bool
{
    let len:usize = in_str.len();
    let mut tol:bool = false;
    let binding = String::from(in_str);
    let char_list = binding.as_bytes();
    let mut i:usize = 0;
    let mut j:usize = len - 1;

    while i != j {
        if char_list[i] != char_list[j] {
            if tol == false {
                if char_list[i + 1] == char_list[i] {
                    i += 1;
                    tol = true;
                    continue;
                } else if char_list[i] == char_list[j - 1] {
                    j -= 1;
                    tol = true;
                    continue;
                } else {
                    return false;
                }
            } else {
                return false;
            }

        }
        i += 1;
        j -= 1;
        if (j - i) == 1 {
            break;
        }
    }

    return true;
}



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_valid_palindrome_ii()
    {
        let mut res:bool = false;

        res = valid_palindrome_ii("abcddcbqa");
        println!("thre result is {res}");
    }
}