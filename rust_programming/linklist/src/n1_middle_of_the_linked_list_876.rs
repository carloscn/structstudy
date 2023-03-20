use utils::linked_list::*;

pub fn middle_node(head: List<i32>) -> List<i32>
{
    let len = head.len();
    let mut ret_list:List<i32> = List::new();
    let mut main_iter = head.into_iter();
    let mut i:usize = 0;

    while let Some(node) = main_iter.next() {
        if i < (len as f64 / 2.0).ceil() as usize {
            ret_list.push(node);
        }
        i += 1;
    }

    return ret_list;
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_middle_node_odd() {
        let mut list = List::new();
        list.push(1);
        list.push(2);
        list.push(3);
        list.push(4);
        list.push(5);
        let ret = middle_node(list);
        utils::linklist::show_i32_list(&ret);
    }
    #[test]
    fn test_middle_node_even() {
        let mut list = List::new();
        list.push(1);
        list.push(2);
        list.push(3);
        list.push(4);
        list.push(5);
        list.push(6);
        let ret = middle_node(list);
        utils::linklist::show_i32_list(&ret);
    }
}