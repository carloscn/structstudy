extern crate utils;
use utils::utils_array_sum_i64;
fn max_average(array: &[i64], k: usize, max_ave: &mut i64) -> i32
{
    let mut _ret:i32 = 0;
    let len:usize = array.len();
    let mut sum:i64 = 0;
    let mut max_sum:i64 = 0;
    let mut j : usize = 0;

    if len == 0 {
        _ret = -1;
        println!("input error!");
        return _ret;
    }

    for i in [0..(len - k)] {
        sum = utils_array_sum_i64(&array[j..], k);
        if sum > max_sum {
            max_sum = sum;
        }
        j += 1;
    }
    *max_ave = sum / (k as i64);

    return _ret;
}

fn test_max_average()
{
    let mut max_ave: i64 = 0;
    let array: [i64;6] = [1,12,-5,-6,50,3];
    let _ret = max_average(&array[0..], 4, &mut max_ave);

    println!("max ave is {max_ave}");
}