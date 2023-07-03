
pub fn max_repeating(sequence: &str, word: &str) -> i32
{
    let mut ret:i32 = 0;

    if sequence.len() < 1 || word.len() < 1 {
        return ret;
    }

    let seq_dup:Vec<char> = sequence.chars().collect();
    let word_dup:Vec<char> = word.chars().collect();

    let mut i:usize = 0;
    while i < seq_dup.len() - word_dup.len() {
        let mut flag:bool = true;
        for j in 0..word_dup.len() {
            if word_dup[j] != seq_dup[i + j] {
                flag = false;
                break;
            }
        }
        if flag == true {
            ret += 1;
        }
        i += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let sequence = "ababc";
        let word = "ab";
        let ret = max_repeating(sequence, word);
        assert_eq!(ret, 2);

        let sequence = "ababc";
        let word = "ba";
        let ret = max_repeating(sequence, word);
        assert_eq!(ret, 1);

        let sequence = "ababc";
        let word = "ac";
        let ret = max_repeating(sequence, word);
        assert_eq!(ret, 0);

        let sequence = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
        let word = "aaaba";
        let ret = max_repeating(sequence, word);
        assert_eq!(ret, 6);
    }
}