
pub fn interpret(command: &str) -> String
{
    if command.len() < 1 {
        return String::new();
    }

    let mut ret:Vec<char> = vec![];
    let cmd:Vec<char> = command.chars().collect();
    let mut i:usize = 0;

    while i < cmd.len() {
        if cmd[i] == 'G' {
            ret.push('G');
        } else if cmd[i] == '(' {
            if i + 1 < cmd.len() && cmd[i + 1] == ')' {
                ret.push('o');
                i += 2;
                continue;
            }
            while  i + 1 < cmd.len() && cmd[i + 1] != ')' {
                ret.push(cmd[i + 1]);
                i += 1;
            }
        }
        i += 1;
    }

    return ret.into_iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let mut ret = interpret("G()(al)");
        assert_eq!(ret, "Goal".to_string());
        let mut ret = interpret("G()()()()(al)");
        assert_eq!(ret, "Gooooal".to_string());
        let mut ret = interpret("(al)G(al)()()G");
        assert_eq!(ret, "alGalooG".to_string());
    }
}