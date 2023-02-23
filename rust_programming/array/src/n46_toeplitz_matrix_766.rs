use std::process;
use std::error::Error;

fn toepitz_matrix(mat:&Vec<[i32;4]>) -> Result<bool, &'static str>
{
    let depth:usize = (*mat).len();
    let width:usize = (*mat)[0].len();
    let mut i:usize = 0;
    let mut j:usize = 0;
    let mut v:Vec<i32> = Vec::new();

    println!("the depth is {depth}");
    if 0 == depth || 0 == width {
        return Err("input len is wrong!\n");
    }

    while i < depth {
        let mut tv:Vec<i32> = (*mat)[i].into_iter().collect();
        v.append(&mut tv);
        i += 1;
    }
    i = 0;

    while i < width - 1 {
        let e = v[i];
        j = i;
        while j < v.len() {
            if e != v[j] {
                return Ok(false);
            }
            j += width + 1;
        }
        i += 1;
    }

    j = 0;
    i = width;
    while j < v.len() - 1 {
        let e = v[i];
        j = i;
        while j < v.len() {
            if e != v[j] {
                return Ok(false);
            }
            j += width + 1;
        }
    }

    return Ok(true);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_toepitz_matrix() {
        //  [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
        let mat:Vec<[i32;4]> = vec![[1,2,3,4],[5,1,2,3],[9,5,1,2]];
        let ret = toepitz_matrix(&mat).unwrap_or_else(|err| {
            eprintln!("error is {err}");
            process::exit(-1);
        });
        assert_eq!(ret, true);
    }
}