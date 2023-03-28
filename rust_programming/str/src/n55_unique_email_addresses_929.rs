use std::ops::Index;

fn sanity_check_domain(dm:&String) -> bool
{
    let dm_vec:Vec<char> = dm.chars().collect();

    if !dm.contains('.') {
        return false;
    }

    if dm_vec[0] == '.' ||
       dm_vec[dm.len() - 1] == '.' {
        return false;
    }

    let index_p = dm_vec.iter().position(|x| *x == '.').unwrap();
    if dm_vec[index_p - 1] == '.' ||
       dm_vec[index_p + 1] == '.' {
        return false;
    }

    return true;
}

fn sanity_check_local(lc:&String) -> bool
{
    let lc_vec:Vec<char> = lc.chars().collect();

    if lc.contains('.') {
        if lc_vec[0] == '.' {
            return false;
        }
    }

    if lc.contains('+') {
        if lc_vec[0] == '+' ||
           lc_vec[lc.len() - 1] == '+' {
            return false;
        }
    }

    return true;
}

pub fn num_unique_emails(emails: Vec<String>) -> i32
{
    let mut ill_mails:Vec<String> = vec![];

    for e in &emails {
        let vc:Vec<&str> = e.split("@").into_iter().collect();
        if vc.len() != 2 {
            continue;
        }
        let domain = vc[1].to_string();
        let mut local = vc[0].to_string();

        if !sanity_check_domain(&domain) {
            continue;
        }

        if !sanity_check_local(&local) {
            continue;
        }

        if local.contains("+") {
            let v_local:Vec<&str> = local.split("+").into_iter().collect();
            local = v_local[0].to_string();
        }

        if local.contains(".") {
            let v_local:String = local.chars().into_iter().filter(|x| *x != '.').collect();
            local = v_local;
        }

        local.push_str("@");
        local.push_str(&domain);

        if !ill_mails.contains(&local) {
            ill_mails.push(local);
        }
    }
    println!("the list is {:?}", ill_mails);
    return ill_mails.len() as i32;
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    // chatGPT provides test cases
    fn test_demo() {
        let email = vec!["test.email+alex@leetcode.com".to_string(),
                                      "test.e.mail+bob.cathy@leetcode.com".to_string(),
                                      "testemail+david@lee.tcode.com".to_string()];
        let ret = num_unique_emails(email);
        assert_eq!(ret, 2);
    }

}