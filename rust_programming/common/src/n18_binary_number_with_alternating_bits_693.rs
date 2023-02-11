
fn has_alternating_bits(n:i32) -> bool
{
    let mut last_bit_status:i32 = 0;
    let mut current_bit_status:i32 = 0;
    let mut e:i32 = n;

    last_bit_status = e & 0x1_i32;
    while e != 0 {
        e >>= 1;
        current_bit_status = e & 0x1_i32;
        if current_bit_status == last_bit_status {
            return false;
        }
        last_bit_status = current_bit_status;
    }

    return true;
}

pub fn test_has_alternating_bits()
{
    let res = has_alternating_bits(0x55);
    println!("the result is {res}");
}