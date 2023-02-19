fn to_lower(instr:&str) -> String
{
    let mut out:String = String::new();
    let mut e:u8;

    for c in instr.as_bytes() {
        e = utils::str::conv_lowercase(*c as u8);
        out.push(e as char);
    }
    // as option:
    // out.push_str(instr);
    // out = instr.to_lowercase();

    return out;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_to_lower_case()
    {
        let ourstr = to_lower("HellO!");
        println!("the output is {ourstr}");
    }
}