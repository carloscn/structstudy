
pub fn sort_people(names: Vec<&str>, heights: Vec<i32>) -> Vec<String>
{
    let mut ret:Vec<String> = vec![];
    if names.len() < 1 || heights.len() < 1 || names.len() != heights.len() {
        return ret;
    }

    let mut input:Vec<(i32, String)> = vec![];
    for i in 0..names.len() {
        input.push((heights[i], names[i].to_string()));
    }

    input.sort_by(|a, b| b.cmp(a));

    for e in input {
        ret.push(e.1);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = sort_people(vec!["Mary","John","Emma"], vec![180,165,170]);
        assert_eq!(ret, vec!["Mary".to_string(),"Emma".to_string(),"John".to_string()]);

        let ret = sort_people(vec!["Alice","Bob","Bob"], vec![155,185,150]);
        assert_eq!(ret, vec!["Bob".to_string(),"Alice".to_string(),"Bob".to_string()]);
    }
}