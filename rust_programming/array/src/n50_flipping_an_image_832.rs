
fn conv_ver(v: &Vec<i32>) -> Vec<i32>
{
    let mut ret_vec:Vec<i32> = v.into_iter()
                                .map(|x| i32::abs(x - 1))
                                .collect();
    ret_vec.reverse();

    return ret_vec;
}

fn flip_image(v: &Vec<Vec<i32>>) -> Vec<Vec<i32>>
{
    let mut ret_vec:Vec<Vec<i32>> = vec![];

    for e in v {
        ret_vec.push(conv_ver(e));
    }

    return ret_vec;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_flip_image_1() {
        let t_image = vec![vec![1,1,0],vec![1,0,1],vec![0,0,0]];
        let ret = flip_image(&t_image);
        assert_eq!(ret, vec![vec![1,0,0],vec![0,1,0],vec![1,1,1]]);
    }

    #[test]
    fn test_flip_image_2() {
        let t_image = vec![vec![1,1,0,0],vec![1,0,0,1],vec![0,1,1,1],vec![1,0,1,0]];
        let ret = flip_image(&t_image);
        assert_eq!(ret, vec![vec![1,1,0,0],vec![0,1,1,0],vec![0,0,0,1],vec![1,0,1,0]]);
    }

}