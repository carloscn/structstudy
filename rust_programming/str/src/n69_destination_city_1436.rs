use std::ops::Index;

pub fn dest_city(paths: Vec<Vec<String>>) -> String
{
    if paths.len() < 1 {
        return "".to_string();
    }

    let mut ret:String = String::new();
    let mut con_paths:Vec<String> = vec![];

    for city in &paths {
        con_paths.push(city[0].clone());
        con_paths.push(city[1].clone());
    }

    let mut dest_city_list:Vec<String> = con_paths.clone();
    let mut single_list:Vec<String> = vec![];
    dest_city_list.sort();

    for e in &dest_city_list {
        if single_list.is_empty() {
            single_list.push(e.clone());
            continue;
        }
        if single_list[single_list.len() - 1] != *e {
            single_list.push(e.clone());
        } else {
            single_list.pop();
        }
    }

    if single_list.len() == 1 {
        ret = single_list[0].clone();
        return ret;
    }

    for city in single_list {
        if con_paths.iter()
                    .position(|r| *r == city).unwrap() & 0x1 == 1 {
            ret = city;
            return ret;
        }
    }

    return ret;
}

#[cfg(test)]
mod tests {
    use std::string;

    use super::*;

    #[test]
    fn demo() {
        let mut ret = dest_city(vec![vec!["London".to_string(),"New York".to_string()],
                                        vec!["New York".to_string(),"Lima".to_string()],
                                        vec!["Lima".to_string(),"Sao Paulo".to_string()]]);
        assert_eq!(ret, "Sao Paulo".to_string());
    }
}