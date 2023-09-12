
pub fn most_words_found(sentences: Vec<&str>) -> i32
{
    let mut ret:i32 = 0;
    if sentences.len() < 1 {
        return ret;
    }

    let mut words_count:i32 = 0;

    for e in sentences {
        words_count = words_count.max(
            1 + e.chars().fold(0, |mut count, ch| {
                if ch == ' ' {
                    count += 1;
                }
                count
        } ));
    }

    ret = words_count;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let mut ret = most_words_found(
                    vec!["alice and bob love leetcode",
                                "i think so too",
                                "this is great thanks very much"]);
        assert_eq!(ret, 6);

        let mut ret = most_words_found(
            vec!["please wait",
                    "continue to fight",
                    "continue to win"]);
        assert_eq!(ret, 3);
    }
}