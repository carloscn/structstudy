use std::cmp::min;

fn shortest_distance(in_str:&String, c:char) -> Result<Vec<i32>, &'static str>
{
    let in_len:usize = in_str.len();
    let in_chars = in_str.chars();
    let mut c_index:Vec<usize> = Vec::new();
    let mut d_ret:Vec<i32> = Vec::new();
    let mut i:usize = 0;
    let mut j:usize = 0;
    let mut min_d:i32 = 0x6fffffff;

    if 0 == in_len {
        return Err("len is 0\n");
    }

    for e in in_chars {
        if e == c {
            c_index.push(i);
        }
        i += 1;
    }
    if 0 == c_index.len() {
        return Err("c_index is 0\n");
    }

    i = 0;
    while i < in_len {
        j = 0;
        while j < c_index.len() {
            let d = i32::abs((c_index[j] as i32) - (i as i32));
            min_d = i32::min(d, min_d);
            j += 1;
        }
        d_ret.push(min_d);
        min_d = 0x6fffffff;
        i += 1;
    }

    return Ok(d_ret);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_shortest_distance() {
        let in_str:String = String::from("loveleetcode");
        let ret = shortest_distance(&in_str, 'e').unwrap_or_else(|err| {
            eprintln!("error is {err}");
            return vec![0, 0, 0];
        });

        assert_eq!(ret, vec![3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]);
    }
}