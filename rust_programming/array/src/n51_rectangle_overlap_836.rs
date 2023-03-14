fn is_overlap(rec1:&Vec<i32>, rec2:&Vec<i32>) -> bool
{
    return check(rec1[0], rec1[2], rec2[0], rec2[2]) &&
    check(rec1[1], rec1[3], rec2[1], rec2[3]);

    fn check(a:i32, b:i32, c:i32, d:i32) -> bool {
        return a < b && c < d && b > c && d > a;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_rec_overlap() {
        {
            let rec1 = vec![0,0,2,2];
            let rec2 = vec![1,1,3,3];
            let mut ret:bool = false;

            ret = is_overlap(&rec1, &rec2);
            assert_eq!(ret, true);
        }
        {
            let rec1 = vec![0,0,1,1];
            let rec2 = vec![1,0,2,1];
            let mut ret:bool = false;

            ret = is_overlap(&rec1, &rec2);
            assert_eq!(ret, false);
        }
        {
            let rec1 = vec![0,0,1,1];
            let rec2 = vec![2,2,3,3];
            let mut ret:bool = false;

            ret = is_overlap(&rec1, &rec2);
            assert_eq!(ret, false);
        }
    }
}