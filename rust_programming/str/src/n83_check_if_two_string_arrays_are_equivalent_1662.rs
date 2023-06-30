
pub fn array_strings_are_equal(word1: Vec<&str>, word2: Vec<&str>) -> bool
{
    if word1.len() < 1 || word2.len() < 1 {
        return false;
    }

    let (mut i_1, mut i_2, mut j_1, mut j_2) = (0, 0, 0, 0);
    let mut e_arr_1:Vec<char> = word1[i_1].chars().collect();
    let mut e_arr_2:Vec<char> = word2[i_2].chars().collect();

    while i_1 < word1.len() || i_2 < word2.len() {

        if e_arr_1[j_1] != e_arr_2[j_2] {
            return false;
        }

        j_1 += 1;
        if j_1 == e_arr_1.len() {
            j_1 = 0;
            i_1 += 1;
            if i_1 < word1.len() {
                e_arr_1 = word1[i_1].chars().collect();
            }
        }

        j_2 += 1;
        if j_2 == e_arr_2.len() {
            j_2 = 0;
            i_2 += 1;
            if i_2 < word2.len() {
                e_arr_2 = word2[i_2].chars().collect();
            }
        }
    }

    return true;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let word1 = vec!["abc", "d", "defg"];
        let word2 = vec!["abcddefg"];
        let ret = array_strings_are_equal(word1, word2);
        assert_eq!(ret, true);

        let word1 = vec!["ab", "c"];
        let word2 = vec!["a", "bc"];
        let ret = array_strings_are_equal(word1, word2);
        assert_eq!(ret, true);


        let word1 = vec!["a", "cb"];
        let word2 = vec!["ab", "c"];
        let ret = array_strings_are_equal(word1, word2);
        assert_eq!(ret, false);
    }
}