
fn get_distance(e1:(i32, i32), e2:(i32, i32)) -> i32
{
    return i32::abs(e1.0 - e2.0) + i32::abs(e1.1 - e2.1);
}

fn is_valid(e1:(i32, i32), point:&Vec<i32>) -> bool
{
    if e1.0 == point[0] || e1.1 == point[1] {
        return true;
    }

    return false;
}

pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32
{
    if points.len() < 1 {
        return 0;
    }

    let cur:(i32, i32) = (x, y);
    let mut min:(i32, i32) = (i32::MAX, i32::MAX);

    for i in 0..points.len() {
        if is_valid(cur, &points[i]) {
            let dist: i32 = get_distance(cur, (points[i][0], points[i][1]));
            if dist < min.1 {
                min.1 = dist;
                min.0 = i as i32;
            }
        }
    }

    if min.0 == i32::MAX {
        min.0 = -1;
    }

    return min.0;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = nearest_valid_point(3, 4, vec![vec![1,2],vec![3,1],vec![2,4],vec![2,3],vec![4,4]]);
        assert_eq!(ret, 2);
        let ret = nearest_valid_point(3, 4, vec![vec![3,4]]);
        assert_eq!(ret, 0);
        let ret = nearest_valid_point(3, 4, vec![vec![2,3]]);
        assert_eq!(ret, -1);
    }
}