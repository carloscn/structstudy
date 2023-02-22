use core::str::Chars;

fn is_contains(in_str:&str, pat_str:&str) -> bool
{
    let mut in_buffer:String = String::from(in_str);
    let mut pat_buffer:String = String::from(pat_str);
    let in_len:usize = in_str.len();
    let pat_len:usize;
    let mut i:usize = 0;
    let mut j:usize = 0;

    utils::str::sort_by_ascend(&mut in_buffer);
    utils::str::to_lowercase(&mut pat_buffer);
    utils::str::filter_letter(&mut pat_buffer);
    utils::str::sort_by_ascend(&mut pat_buffer);

    let in_char:Vec<char> = in_buffer.chars().into_iter().collect();
    let pat_char:Vec<char> = pat_buffer.chars().into_iter().collect();

    println!("pat is {:?}", in_char);
    println!("in  is {:?}", pat_char);

    pat_len = pat_char.len();

    while j < in_len {
        if in_char[j] == pat_char[i] {
            i += 1;
        }
        j += 1;
        if i == pat_len {
            return true;
        }
    }
    return false;
}


fn shortest_word(str_vec:&Vec<String>, pat:String) -> Result<String, &'static str>
{
    let mut i:usize = 0;
    let v_len = str_vec.len();
    let mut min_len:usize = 0xfffffff;
    let mut len:usize = 0;
    let mut index:usize = 0;

    while i < v_len {
        let ret = is_contains(&str_vec[i], &pat);
        if true == ret {
            println!("found {}", str_vec[i]);
            len = str_vec[i].len();
            if min_len > len {
                min_len = len;
                index = i;
            }
        }
        i += 1;
    }
    println!("the index is {index}");
    return Ok(str_vec[index].clone());
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_shorest_word() {
        let str_vec:Vec<String> =
            vec!["step".to_string(),
                 "steps".to_string(),
                 "stripe".to_string(),
                 "stepple".to_string()];
        let ret = shortest_word(&str_vec, "1s3 PSt".to_string()).unwrap_or_else( |err| {
            eprintln!("return a error {}", err);
            panic!("error! {}", err);
        });
        assert_eq!(ret, "steps".to_string());
    }
}