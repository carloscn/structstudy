fn find_pivot_index(array:&[i64]) -> i32
{
    let mut i:usize = 0;
    let mut j:usize = array.len() - 1;
    let mut lsum:i64 = array[i];
    let mut rsum:i64 = array[j];

    while i <= j {
        if lsum > rsum {
            j -= 1;
            rsum += array[j];
        } else if lsum < rsum {
            i += 1;
            lsum += array[i];
        } else {
            return (i + 1) as i32;
        }
    }

    return -1_i32;
}

pub fn test_find_pivot_index()
{
    let array = [1, 7, 3, 6, 5, 6];
    let mut index:i32;

    index = find_pivot_index(&array);
    println!("the index is {index}.");
}