
// 1 2 3 4 5 6 7 8 9 10

// 1 2 10 / 1 2 9 / 1 2 8 / 1 2 7 / 1 2 6 / 1 2 5 / 1 2 4 / 1 2 3
// 1 3 10 / 1 3 9 / ... / 1 3 4
// 1 4 10 / 1 4 9 / ... / 1 4 5
// 2 3 10 / 2 3 9
// ...
// ...

pub fn count_triples(n: i32) -> i32
{
    if n < 3 {
        return 0;
    }

    let mut ret:i32 = 0;

    for i in 1..n + 1 {
        for j in (i + 1)..n + 1 {
            for k in (j + 1)..n + 1{
                if  i * i + j * j == k * k {
                    ret += 2;
                }
            }
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let ret = count_triples(5);
        assert_eq!(ret, 2);
        let ret = count_triples(10);
        assert_eq!(ret, 4);
    }
}