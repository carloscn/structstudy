
pub fn check_distances(s: &str, distance: Vec<i32>) -> bool
{
    let mut ret:bool = false;
    if s.len() < 1 || distance.len() < 1 {
        return ret;
    }

    let dup_s:Vec<char> = s.chars().collect();
    let mut dup_v:Vec<i32> = vec![];

    for i in 0..dup_s.len() {
        let target = dup_s[i];
        for j in (i + 1)..dup_s.len() {
            if dup_s[j] == target {
                dup_v.push((j - i - 1) as i32);
            }
        }
    }

    for i in 0..distance.len() {
        if (i < dup_v.len() && dup_v[i] != distance[i]) {
            return false;
        }
    }

    ret = true;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = check_distances("abaccb", vec![1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]);
        assert_eq!(ret, true);

        let ret = check_distances("aa", vec![1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]);
        assert_eq!(ret, false);
    }
}