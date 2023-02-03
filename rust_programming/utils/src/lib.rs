
pub fn utils_max(n:u64, m:u64) -> u64
{
    if n > m {
        return n;
    } else {
        return m;
    }
}

pub fn utils_is_capital(c : char) -> bool
{
    let mut ret = false;

    if (c >= 'A') && (c <= 'Z') {
        ret = true;
    }

    return ret;
}

pub fn utils_is_lowercase(c : char) -> bool
{
    let mut ret = false;

    if (c >= 'a') && (c <= 'z') {
        ret = true;
    }

    return ret;
}