


fn count_num(in_str: &str) -> bool
{
    let len:usize = in_str.len();
    let mut count_a:usize = 0;
    let mut count_b:usize = 0;
    let mut reversed:bool = false;
    let in_bytes = in_str.as_bytes();
    let mut byte:u8 = in_bytes[0].clone();

    if len < 2_usize {
        return false;
    }

    for i in in_bytes {

        if (reversed == false) && (byte == *i) {
            count_a += 1;
            byte = (*i).clone();
            continue;
        } else {
            reversed = true;
            byte = (*i).clone();
        }

        if (reversed == true) && (byte == *i) {
            count_b += 1;
            byte = (*i).clone();
            continue;
        } else {
            return false;
        }
    }

    if count_a == count_b {
        return true;
    } else {
        return false;
    }

}

fn count_binary_substr(in_str:&str) -> usize
{
    let mut count:usize = 0;
    let sub_vec:Vec<String> = utils::str::append_all_substr(in_str);
    let mut i:usize = 0;
    let mut result:bool = false;

    while i < sub_vec.len() {
        result = count_num(&sub_vec[i]);
        if result == true {
            count += 1;
            println!("found {}", &sub_vec[i]);
        }
        i += 1;
    }
    return count;
}

pub fn test_count_binary_substrings()
{
    let mut count:usize = 0;
    count = count_binary_substr("00110011");
    println!("{:#?}", count);
}