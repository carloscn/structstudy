

fn most_common_word(paragraph:&String, banlist:&Vec<String>) -> Result<String, &'static str>
{
    let mut count:usize = 0;
    let mut max_count:usize = 0;
    let mut index:usize = 0;
    let mut max_index:usize = 0;
    let param:String = paragraph.to_lowercase();
    let mut param_vec:Vec<&str> =  param.split(' ')
        .map(|x:&str| {
            x.trim_end_matches(|a:char| ('!' == a) ||
                                        ('?' == a) ||
                                        (';' == a) ||
                                         ('.' == a) ||
                                         (' ' == a) ||
                                         (',' == a) ||
                                         ('\'' == a) )
            }
        ).collect();
    param_vec = param_vec.iter().filter(|&x| !(*banlist).contains(&x.to_string())).cloned().collect();

    for e in &param_vec {
        for k in &param_vec {
            if **e == **k {
                count += 1;
            }
        }
        if count > max_count {
            max_count = count;
            max_index = index;
        }
        count = 0;
        index += 1;
    }

    Ok(param_vec[max_index].to_string())
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_most_common_word() {
        let paragraph:String = "Bob hit a ball, the hit BALL flew far after it was hit.".to_string();
        let banlist:Vec<String> = vec!["hit".to_string()];
        let ret = most_common_word(&paragraph, &banlist).unwrap_or_else(|err| {
            eprintln!("error {err}");
            return "error!".to_string();
        });
        assert_eq!(ret, "ball".to_string());
    }
}