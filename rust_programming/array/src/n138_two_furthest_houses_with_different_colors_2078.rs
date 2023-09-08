
pub fn max_distance(colors: Vec<i32>) -> i32
{
    let mut ret:i32 = -1;

    if colors.len() < 1 {
        return ret;
    }

    let mut max_dist:i32 = -1;

    for i in 0..colors.len() {
        for j in (i + 1)..colors.len() {
            if colors[i] != colors[j] {
                max_dist = max_dist.max(i32::abs(i as i32 - j as i32));
            }
        }
    }

    ret = max_dist;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret =  max_distance(vec![1,1,1,6,1,1,1]);
        assert_eq!(ret, 3);
        let ret =  max_distance(vec![1,8,3,8,3]);
        assert_eq!(ret, 4);
        let ret =  max_distance(vec![0,1]);
        assert_eq!(ret, 1);
    }
}