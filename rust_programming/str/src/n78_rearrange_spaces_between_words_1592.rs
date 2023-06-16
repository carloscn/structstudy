
pub fn reorder_spaces(text: String) -> String
{
    if text.is_empty() {
        return text;
    }

    let mut space_count:usize = 0;
    let mut str_vec:Vec<char> = vec![];
    let mut words_list:Vec<String> = vec![];
    let text_vec:Vec<char> = text.chars().collect();

    for i in 0..text_vec.len() {
        if text_vec[i] == ' ' {
            space_count += 1;
            if !str_vec.is_empty() {
                words_list.push(str_vec.clone().into_iter().collect());
                str_vec.clear();
            }
        } else {
            str_vec.push(text_vec[i]);
        }
    }

    if !str_vec.is_empty() {
        words_list.push(str_vec.clone().into_iter().collect());
        str_vec.clear();
    }

    let left:usize;
    if words_list.len() > 1 {
        left = space_count % (words_list.len() - 1);
        space_count = space_count / (words_list.len() - 1);
    } else {
        left = 0;
        space_count = 0;
    }

    let mut ret:Vec<char> = vec![];
    for i in 0..words_list.len() {
        ret.append(&mut words_list[i].chars().collect());
        if i < words_list.len() - 1 {
            ret.append(&mut vec![' '; space_count]);
        } else {
            if left != 0 {
                ret.append(&mut vec![' '; 1]);
            }
        }
    }

    return ret.into_iter().collect();
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn demo() {
        let mut ret = reorder_spaces("  this   is  a sentence ".to_string());
        assert_eq!(ret, "this   is   a   sentence".to_string());
        let mut ret = reorder_spaces(" practice   makes   perfect".to_string());
        assert_eq!(ret,"practice   makes   perfect ".to_string());
        let mut ret = reorder_spaces("hello   world".to_string());
        assert_eq!(ret,"hello   world".to_string());
        let mut ret = reorder_spaces("  walks  udp package   into  bar a".to_string());
        assert_eq!(ret,"walks  udp  package  into  bar  a ".to_string());
        let mut ret = reorder_spaces(" a".to_string());
        assert_eq!(ret,"a".to_string());
    }
}