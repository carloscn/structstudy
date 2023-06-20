
pub fn trim_mean(arr: Vec<i32>) -> f64
{
    let mut ret:f64 = 0.0f64;

    if arr.len() < 1 {
        return ret;
    }

    let mut arr_dup:Vec<i32> = arr.clone();
    let mut cut_len:usize = (arr.len() as f32 * 0.05_f32) as usize;
    let mut sum:i32 = 0;

    arr_dup.sort();

    for i in cut_len..arr.len() - cut_len {
        sum += arr_dup[i];
    }

    ret = (sum as f64) / (arr.len() - 2 * cut_len) as f64;

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = trim_mean(vec![1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]);
        assert_eq!(ret, 2.000f64);
        let ret = trim_mean(vec![6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]);
        assert_eq!(ret, 4.000f64);
        let ret = trim_mean(vec![6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]);
        assert_eq!(ret <= 4.77778, true);
        let ret = trim_mean(vec![9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,
                                          8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,
                                          0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]);
        assert_eq!(ret <= 5.27778, true);
        let ret = trim_mean(vec![4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,
                                           3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,
                                           2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]);
        assert_eq!(ret <= 5.29167, true);
    }
}