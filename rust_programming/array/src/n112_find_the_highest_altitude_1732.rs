
pub fn largest_altitude(gain: Vec<i32>) -> i32
{
    if gain.len() < 1 {
        return 0;
    }

    let mut r_v:Vec<i32> = vec![0];

    for i in 0..gain.len() {
        let e = r_v[i] + gain[i];
        r_v.push(e);
    }

    return r_v.iter().fold(i32::MIN, |count, x| count.max(*x));
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = largest_altitude(vec![-5,1,5,0,-7]);
        assert_eq!(ret, 1);
        let ret = largest_altitude(vec![-4,-3,-2,-1,4,3,2]);
        assert_eq!(ret, 0);
    }
}