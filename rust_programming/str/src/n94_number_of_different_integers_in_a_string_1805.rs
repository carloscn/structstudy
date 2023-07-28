use std::vec;

pub fn num_different_integers(word: &str) -> i32
{
    if word.len() < 1 {
        return 0;
    }

    let wv:String = word.chars().map(|x| {
        if !x.is_numeric() {
            ' '
        } else{
            x
        }
    }).collect();

    let mut nums:Vec<i32> = vec![];
    for e in wv.split(' ') {
        if !e.is_empty() {
            nums.push(e.parse().unwrap());
        }
    }

    nums.sort();
    nums.dedup();

    return nums.len() as i32;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = num_different_integers("a123bc34d8ef34");
        assert_eq!(ret, 3);
        let ret = num_different_integers("leet1234code234");
        assert_eq!(ret, 2);
        let ret = num_different_integers("a1b01c001");
        assert_eq!(ret, 1);
    }
}