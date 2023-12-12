
pub fn last_visited_integers(words: Vec<&str>) -> Vec<i32>
{
    let mut ret = vec![];
    if words.len() < 1 {
        return ret;
    }
    let mut rom:Vec<i32> = vec![];
    for i in 0..words.len() {
        // match number
        if words[i] != "prev" {
            rom.push(words[i].parse().unwrap());
            continue;
        }

        // match "prev"
        if i == 0 {
            ret.push(-1);
            continue;
        }

        let mut j:usize = i;
        let mut prev_count: usize = 0;
        while j >= 0 {
            if words[j] == "prev" {
                prev_count += 1;
            } else {
                if prev_count > rom.len() {
                    ret.push(-1);
                } else {
                    ret.push(rom[rom.len() - prev_count]);
                }
                break;
            }
            j -= 1;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = last_visited_integers(vec!["1","2","prev","prev","prev"]);
        assert_eq!(ret, [2,1,-1]);

        let ret = last_visited_integers(vec!["1","prev","2","prev","prev"]);
        assert_eq!(ret, [1,2,1]);
    }
}