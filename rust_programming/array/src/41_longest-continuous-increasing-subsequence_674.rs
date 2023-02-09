use core::fmt::Error;

fn longest_continuous_seq(array:&[i64], len:&mut usize) -> Result<i32, &'static str>
{
    let mut i = 1;
    let mut count = 0;
    let mut max_count = 0;

    if 0 == *len {
        return Err("input error");
    }

    while i < *len {
        if array[i] > array[i - 1] {
            count += 1;
            if count > max_count {
                max_count = count;
            }
        } else {
            count = 0;
        }
        i += 1;
    }

    *len = max_count + 1;

    return Ok(0);
}

fn test_longest_continuous_seq()
{
    let array = [1i64,3,5,4,7];
    let mut len:usize = array.len();

    let ret = longest_continuous_seq(&array, &mut len);
    match ret {
        Ok(v) => {}
        Err(e) => {
            println!("error parsing header: {:?}", e);
            return
        }
    }

    println!("the longest is {len}");
}