
fn init(father:&mut Vec<i32>)
{
    for i in 0..father.len() {
        father[i] = i as i32;
    }
}

fn find(father:&mut Vec<i32>, u:i32) -> i32
{
    if u != father[u as usize] {
        father[u as usize] = find(father, father[u as usize]);
        return father[u as usize];
    } else {
        return u;
    }
}

fn join(father:&mut Vec<i32>, u:i32, v:i32)
{
    let a = find(father, u);
    let b = find(father, v);
    if a == b {
        return;
    }
    father[b as usize] = a;
}

fn same(father:&mut Vec<i32>, u:i32, v:i32) -> bool
{
    let a = find(father, u);
    let b = find(father, v);
    return a == b;
}

pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool
{
    let mut i:usize = 0;
    let mut father:Vec<i32> = vec![0;n as usize];

    init(&mut father);

    for i in 0..edges.len() {
        join(&mut father, edges[i][0], edges[i][1]);
    }

    return same(&mut father, source, destination);
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = valid_path(3, vec![vec![0,1],vec![1,2],vec![2,0]], 0, 2);
        assert_eq!(ret, true);
        let ret = valid_path(6, vec![vec![0,1],vec![0,2],vec![3,5],vec![5,4],vec![4,3]], 0, 5);
        assert_eq!(ret, false);
    }
}