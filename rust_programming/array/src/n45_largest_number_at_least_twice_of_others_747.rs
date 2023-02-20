use std::error::Error;
use std::process;

fn larget_number(array:&[i64]) -> Result<usize, &'static str>
{
    let mut index:usize = 0;
    let len:usize = array.len();
    let mut buffer:Vec<i64> = Vec::new();
    let mut index:Vec<usize> = Vec::new();
    let mut i:usize = 0;
    let mut j:usize = 0;

    if 0 == len {
        return Err("input array len is null\n");
    }

    while i < len {
        buffer.push(array[i]);
        index.push(i);
        i += 1;
    }
    i = 0;

    while i < len {
        while j < len - i - 1 {
            if buffer[j] < buffer[j + 1] {
                buffer.swap(j, j + 1);
                index.swap(j, j + 1);
            }
            j += 1;
        }
        i += 1;
    }

    if buffer[0] >= 2 * buffer[1] {
        return Ok(index[0]);
    } else {
        return Ok(!0 as usize);
    }
}

#[cfg(test)]
mod tests {
    use super::larget_number;

    #[test]
    pub fn test_large_number() {
        let array = [3_i64,6,1,0];
        let ret:usize = larget_number(&array).unwrap_or_else(|err| {
            eprintln!("input number error, {}", err);
            return 0xfffff;
        });
        assert_eq!(ret, 1);
    }
}