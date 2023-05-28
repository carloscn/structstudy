
pub fn final_prices(prices: Vec<i32>) -> Vec<i32>
{
    if prices.len() < 1 {
        return prices;
    }

    let mut ret:Vec<i32> = vec![];

    for i in 0..prices.len() - 1 {
        let mut j = i;
        let mut e = -1;
        while e < 0 && j < prices.len() - 1 {
            j += 1;
            e = prices[i] - prices[j];
        };

        if j == prices.len() - 1 {
            e = prices[i];
        }

        ret.push(e);
    }

    ret.push(prices[prices.len() - 1]);

    return ret;
}

#[cfg(test)]
mod tests {
    use std::assert_eq;

    use super::*;
    #[test]
    fn test_demo() {
        let ret = final_prices(vec![8,4,6,2,3]);
        assert_eq!(ret, vec![4,2,4,2,3]);
        let ret = final_prices(vec![1,2,3,4,5]);
        assert_eq!(ret, vec![1,2,3,4,5]);
        let ret = final_prices(vec![10,1,1,6]);
        assert_eq!(ret, vec![9,0,1,6]);
    }
}