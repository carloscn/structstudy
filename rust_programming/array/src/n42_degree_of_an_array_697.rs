
// 1,2,2,3,1

use utils::num::min;

fn degree_array(vec: &[i64]) -> usize
{
    let mut count:usize = 0;
    let mut max_count:usize = 0;
    let mut ind:usize = 0;
    let mut min_index:usize = 0;
    let mut buffer:Vec<i64> = Vec::from(vec);
    let mut index:Vec<i64> = Vec::from(vec);
    let len:usize = vec.len();
    let mut i:usize = 0;
    let mut j:usize = 0;

    println!("the len is {len}");

    while i < len {
        index[i] = i as i64;
        i += 1;
    }

    for i in 0..len {
        for j in 0..len - 1 - i {
            if buffer[j] > buffer[j + 1] {
                println!("swap the index {j}, {}", j + 1);
                buffer.swap(j, j + 1);
                index.swap(j, j + 1);
            }
        }
    }

    println!("buffer is {:?}", buffer);
    println!("index  is {:?}", index);

    j = 0;
    for i in 0..len - 1 {
        if buffer[i] == buffer[i + 1] {
            count += 1;
            if (count >= 1) && (count > max_count) {
                ind = i64::abs((index[i + 1] as i64) - (index[j] as i64)) as usize;
                if (ind > min_index) {
                    min_index = ind;
                }
            } else if (count >= 1) && (count == max_count) {
                ind = i64::abs((index[i + 1] as i64) - (index[j] as i64)) as usize;
                if (ind < min_index) {
                    min_index = ind;
                }
            }
            if count > max_count {
                max_count = count;
            }
        } else {
            count = 0;
            j = i + 1;
        }
    }

    return min_index + 1;
}


pub fn test_degree_array()
{
    let vec1:Vec<i64> = vec![1,2,2,3,1];
    let mut n:usize = degree_array(&vec1);
    println!("the n1 is {n}");

    let vec2:Vec<i64> = vec![1,2,2,3,1,4,2];
    n = degree_array(&vec2);
    println!("the n2 is {n}");

}