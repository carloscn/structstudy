
fn jewels_and_stones(jewels:&String, stones:&String) -> Result<usize, &'static str>
{
    let jew_len:usize = jewels.len();
    let sto_len:usize = stones.len();
    let mut count:usize = 0;

    if (0 == jew_len) ||
       (0 == sto_len) {
        return Err("input len is wrong!\n");
    }

    let sto_chars = stones.chars();

    for e in sto_chars {
        if jewels.contains(e) {
            count += 1
        }
    }

    return Ok(count);
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_jewels_and_stones() {
        let jew = "aA".to_string();
        let sto = "aAAAbbbb".to_string();
        let ret:usize = jewels_and_stones(&jew, &sto).unwrap_or_else(|err| {
            eprintln!("error is {}", err);
            return 0;
        });
        assert_eq!(ret, 4);
    }
}