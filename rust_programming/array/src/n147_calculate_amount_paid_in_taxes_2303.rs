
pub fn calculate_tax(brackets: Vec<Vec<i32>>, income: i32) -> f64
{
    let mut ret:f64 = 0.0f64;

    if brackets.len() == 0 || income == 0 {
        return ret;
    }

    let mut i:usize = 0;
    let mut left:f64 = income as f64;
    let mut last_base:f64 = 0.0;
    while i < brackets.len() && left >= 0.0 {
        let e = &brackets[i];
        let tax_pay = (e[0] as f64 - last_base).min(left) as f64 * e[1] as f64 / 100.0_f64;
        left -= (e[0] as f64 - last_base).min(left) as f64;
        last_base = e[0] as f64;
        ret += tax_pay;
        i += 1;
    }

    return ret;
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let ret = calculate_tax(vec![vec![3,50],vec![7,10],vec![12,25]], 10);
        assert_eq!(ret, 2.65f64);

        let ret = calculate_tax(vec![vec![1,0],vec![4,25],vec![5,50]], 2);
        assert_eq!(ret, 0.25f64);

        let ret = calculate_tax(vec![vec![2,50]], 0);
        assert_eq!(ret, 0.0);
    }
}