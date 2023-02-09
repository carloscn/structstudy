fn is_move_back(vector: &str) -> bool
{
    let mut pos = (0_i32 ,0_i32);

    if vector.len() == 0 {
        return true;
    }

    for e in vector.chars() {
        match e {
            'l' | 'L' => pos.0 += 1,
            'r' | 'R' => pos.0 -= 1,
            'u' | 'U' => pos.1 += 1,
            'd' | 'D' => pos.1 -= 1,
            _ => return false
        }
    }

    if pos == (0 ,0) {
        return true;
    } else {
        return false;
    }
}

pub fn test_is_move_back()
{
    let vector = "LRUDD".to_string();
    let ret = is_move_back(&vector);
    println!("the return is {ret}");
}