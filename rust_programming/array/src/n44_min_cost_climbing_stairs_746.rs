use std::error::Error;
use std::process;

fn min_cost_climbing(cost:&Vec<i32>) -> Result<i32, &'static str>
{
    let mut dp:Vec<i32> = Vec::new();
    let mut i:usize = 2;

    if cost.len() < 1 {
        return Err("the input cost error!");
    }

    dp.push(0);
    dp.push(0);

    while i <= cost.len() {
        let pre_dp = dp[i - 2] + cost[i - 2];
        let post_dp = dp[i - 1] + cost[i - 1];
        dp.push(std::cmp::min(pre_dp, post_dp));
        i += 1;
    }

    return Ok(dp[cost.len()]);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_min_cost_climbing()
    {
        let vec:Vec<i32> = vec![1,100,1,1,1,100,1,1,100,1];
        let spend = min_cost_climbing(&vec).unwrap_or_else(|err| {
            eprintln!("ploblem input vec! err: {err}");
            process::exit(1);
        });

        println!("the spend is {spend}");
        assert_eq!(spend, 6);
    }
}