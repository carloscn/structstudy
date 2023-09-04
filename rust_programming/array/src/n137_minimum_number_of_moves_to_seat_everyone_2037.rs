
pub fn min_moves_to_seat(seats: Vec<i32>, students: Vec<i32>) -> i32
{
    let mut ret:i32 = 0;

    if seats.len() < 1 || students.len() != seats.len() {
        return ret;
    }

    let mut seat_dup = seats.clone();
    let mut stud_dup = students.clone();

    seat_dup.sort();
    stud_dup.sort();

    for i in 0..seat_dup.len() {
        ret += i32::abs(seat_dup[i] - stud_dup[i]);
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = min_moves_to_seat(vec![3,1,5], vec![2,7,4]);
        assert_eq!(ret, 4);
        let ret = min_moves_to_seat(vec![4,1,5,9], vec![1,3,2,6]);
        assert_eq!(ret, 7);
        let ret = min_moves_to_seat(vec![2,2,6,6], vec![1,3,2,6]);
        assert_eq!(ret, 4);
    }
}