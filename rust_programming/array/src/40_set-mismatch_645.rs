extern crate utils;

fn mis_set(array : &mut [i64], len : &mut usize) -> i32
{
    let mut ret:i32 = 0;
    let mut i:usize = 0;
    let mut count:usize = 0;
    let mut sz = *len;

    if sz == 0 {
        return ret;
    }

    while i < sz {
        if array[i] != (i + 1) as i64 {
            array[count] = array[i];
            count += 1;
            array[count] = (i + 1) as i64;
            count += 1;
        }
        i += 1;
    }
    *len = count;

    return ret;
}

fn test_mis_set()
{
    let mut array:[i64;4] = [1,2,2,4];
    let mut len:usize = array.len();
    let mut i:usize = 0;

    let ret = mis_set(&mut array, &mut len);
    if ret != 0 {
        println!("failed!\n");
    }
    println!("len is {len}");

    while i < len {
        print!("{},", array[i]);
        i += 1;
    }
    println!(" ");

}