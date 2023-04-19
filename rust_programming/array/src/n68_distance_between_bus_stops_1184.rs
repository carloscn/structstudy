
pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32
{
    let mut ret = 0;

    if distance.len() <= destination as usize ||
       start > destination {
        return -1;
    }

    if distance.len() < 1 || start == destination {
        return ret;
    }

    let mut pos_count:i32 = 0;
    let mut neg_count:i32 = 0;
    for i in 0..distance.len() as i32 {
        if i >= start && i < destination {
            pos_count += distance[i as usize];
        } else {
            neg_count += distance[i as usize];
        }
    }

    ret = pos_count.min(neg_count);

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_demo() {
        let ret = distance_between_bus_stops(vec![1,2,3,4], 0, 1);
        assert_eq!(ret,1);
        let ret = distance_between_bus_stops(vec![1,2,3,4], 0, 2);
        assert_eq!(ret,3);
        let ret = distance_between_bus_stops(vec![1,2,3,4], 0, 3);
        assert_eq!(ret,4);
    }
}