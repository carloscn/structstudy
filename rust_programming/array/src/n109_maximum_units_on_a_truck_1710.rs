
pub fn maximum_units(box_types: Vec<Vec<i32>>, truck_size: i32) -> i32
{
    if box_types.len() < 1 || truck_size == 0 {
        return 0;
    }

    let mut ret:i32 = 0;
    let mut box_vec:Vec<Vec<i32>> = box_types.clone()
                                             .iter_mut()
                                             .map(|x| {
        let t = x[0];
        x[0] = x[1];
        x[1] = t;
        x.clone()
    }).collect::<Vec<Vec<i32>>>();

    box_vec.sort();
    box_vec.reverse();

    let mut box_num:i32 = 0;
    for e in box_vec {
        if box_num + e[1] < truck_size {
            ret += e[1] * e[0];
            box_num += e[1];
        } else {
            ret += (box_num + e[1] - truck_size) * e[0];
            break;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = maximum_units(vec![vec![5,10],vec![2,5],vec![4,7],vec![3,9]], 10);
        assert_eq!(ret, 91);
    }
}