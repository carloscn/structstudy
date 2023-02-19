fn find_letter(instr: &str, target: u8) -> u8
{
    let mut left:usize = 0;
    let mut right:usize = instr.len() - 1;
    let mut pivot:usize;
    let mut ret:u8;
    let instr_array = instr.as_bytes();

    while left <= right {
        pivot = left + (right - left) / 2;
        if target < instr_array[pivot] {
            right = pivot - 1;
        } else {
            left = pivot + 1;
        }
    }
    ret = instr_array[left % instr.len()];

    return ret;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_find_letter()
    {
        let mut ins:u8 = 'y' as u8;
        let c:u8 = find_letter("abcdefghijklmnopqrstuvwxyz", ins);
        println!("the c is {}", c as char);
    }
}