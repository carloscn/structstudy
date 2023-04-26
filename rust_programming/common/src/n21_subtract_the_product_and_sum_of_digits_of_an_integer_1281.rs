
pub fn subtract_product_and_sum(n: i32) -> i32
{
    if n < 1 {
        return 0;
    }

    let mut product:i32 = 1;
    let mut sum:i32 = 0;
    let mut nd:i32 = n;

    while nd != 0 {
        let e:i32 = nd % 10;
        product *= e;
        sum += e;
        nd /= 10;
    }

    return product - sum;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_demo() {
        let mut ret = subtract_product_and_sum(234);
        assert_eq!(ret, 15);

        ret = subtract_product_and_sum(4421);
        assert_eq!(ret, 21);
    }
}