
fn binary_gap(n: i32) -> i32
{
    let mut input:i32 = n;
    let mut queue:Vec<i32> = vec![];
    let mut max:i32 = 0;

    while input != 0 {
        let mut m = 0;
        let mut d:i32 = 0;
        m = input % 2;
        // en-queue
        if (queue.is_empty() && 1 == m) ||
           (!queue.is_empty() && 0 == m) {
            queue.push(m);
        }
        // de-queue
        if !queue.is_empty() && 1 == m {
            d = (queue.len() - 1) as i32;
            max = d.max(max);
            queue.clear();
            queue.push(m);
        }
        input /= 2;
    }

    max
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    // chatGPT provides test cases
    fn test_binary_gap_all_zero() {
        assert_eq!(binary_gap(0b00000000), 0);
    }

    #[test]
    fn test_binary_gap_all_one() {
        assert_eq!(binary_gap(0b11111111), 0);
    }

    #[test]
    fn test_binary_gap_no_gap() {
        assert_eq!(binary_gap(0b01010101), 1);
    }

    #[test]
    fn test_binary_gap_single_gap() {
        assert_eq!(binary_gap(0b01000101), 3);
    }

    #[test]
    fn test_binary_gap_multiple_gaps() {
        assert_eq!(binary_gap(0b1001011001), 2);
    }

    #[test]
    fn test_binary_gap_gap_at_end() {
        assert_eq!(binary_gap(0b00100000), 0);
    }

    #[test]
    fn test_binary_gap_gap_at_beginning() {
        assert_eq!(binary_gap(0b10000000), 0);
    }

}