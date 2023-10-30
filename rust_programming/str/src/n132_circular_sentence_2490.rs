
pub fn is_circular_sentence(sentence: &str) -> bool
{
    if sentence.is_empty() {
        return false;
    }

    let input_vec:Vec<String> = sentence.split(' ').map(|x| x.to_string()).collect();

    let mut i:usize = 0;
    let mut j:usize = 0;
    let mut sum_vec:Vec<char> = vec![];
    loop {
        let mut e_vec:Vec<char> = input_vec[i].chars().collect();
        if sum_vec.is_empty() {
            sum_vec.append(&mut e_vec);
        } else {
            if sum_vec[sum_vec.len() - 1] != e_vec[0] {
                return false;
            }
            sum_vec.append(&mut e_vec);
        }
        j += 1;
        i = (i + 1) % input_vec.len();
        if j > input_vec.len() + 1 {
            break;
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = is_circular_sentence("leetcode exercises sound delightful");
        assert_eq!(ret, true);

        let ret = is_circular_sentence("eetcode");
        assert_eq!(ret, true);

        let ret = is_circular_sentence("Leetcode is cool");
        assert_eq!(ret, false);
    }
}