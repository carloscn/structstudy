// https://github.com/jlkiri/rust-data-structures/tree/master/src

use std::mem;

#[derive(Debug, PartialEq)]
pub struct Node<T> {
    pub value: T,
    pub next: Option<Box<Node<T>>>,
}
type Link<T> = Option<Box<Node<T>>>;

#[derive(Debug)]
pub struct List<T> {
    len: usize,
    head: Link<T>,
}

impl<T: std::cmp::PartialEq> List<T> {
    pub fn new() -> Self {
        List { len:0, head: None }
    }

    pub fn len(&self) -> usize {
        self.len
    }

    pub fn show(&self) {
        //println!("list is {:?}", self);
    }

    pub fn push(&mut self, item: T) {
        let next_node = Box::new(Node {
            value: item,
            next: self.head.take(),
        });
        self.len += 1;
        self.head = Some(next_node)
    }

    pub fn pop(&mut self) -> Option<T> {
        if self.len == 0 {
            panic!("no value to pop.")
        }

        self.head.take().map(|node| {
            self.head = node.next;
            self.len -= 1;
            node.value
        })
    }

    pub fn next(&mut self) -> Link<T> {
        self.head.take().map(|node| {
            node.next.unwrap()
        })
    }

    pub fn peek(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.value)
    }

    fn peek_by_unwrap(&self) -> Option<&T> {
        if self.len == 0 {
            return None;
        }
        return Some(&self.head.as_ref().unwrap().value);
    }

    fn peek_mut(&mut self) -> Option<&mut T> {
        if self.len == 0 {
            return None;
        }
        self.head.as_mut().map(|node| {
            &mut node.value
        })
    }

    fn peek_and_update(&mut self, new_value: T) {
        if self.len == 0 {
            return ();
        }
        self.head.as_mut().map(|node| {
            node.value = new_value;
        });
    }


}


impl<T> Drop for List<T> {
    fn drop(&mut self) {
        let mut cur_node = self.head.take();
        while let Some(mut temp_node) = cur_node {
            cur_node = temp_node.next.take();
        }
    }
}

pub trait Iterator {
    type Item;
    fn next(&mut self) -> Option<Self::Item>;
}

pub struct IntoIter<T> (List<T>);

impl<T> Iterator for IntoIter<T> {
    type Item = T;

    fn next(&mut self) -> Option<self::Item> {
        self.0.pop()
    }
}

impl<T> List<T> {
    // type: List<T> ---> (List<T>>)
    pub fn into_iter(self) -> IntoIter<T> {
        IntoIter(self)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn linked_push() {
        let mut list: List<isize> = List::new();
        list.push(1);
        list.push(2);
        assert_eq!(list.pop(), Some(2));
        assert_eq!(list.pop(), Some(1));
    }

    #[test]
    fn linked_peek() {
        let mut list: List<isize> = List::new();
        list.push(1);
        list.push(2);
        assert_eq!(list.peek(), Some(&2));
    }
    #[test]
    fn basics2() {
        let mut list = List::new();
        // Populate list
        list.push(1);
        list.push(2);
        list.push(3);
        // Check normal removal
        assert_eq!(list.pop(), Some(3));
        assert_eq!(list.pop(), Some(2));
    }

    #[test]
    fn peek2() {
        let mut list = List::new();
        assert_eq!(list.peek(), None);
        assert_eq!(list.peek_mut(), None);
        list.push(1);
        list.push(2);
        list.push(3);

        assert_eq!(list.peek(), Some(&3));
        assert_eq!(list.peek_mut(), Some(&mut 3));
        list.peek_and_update(4);
        assert_eq!(list.peek(), Some(&4));

        list.peek_mut().map(|value| {
            *value = 42
        });

        assert_eq!(list.peek(), Some(&42));
        assert_eq!(list.pop(), Some(42));
    }
    #[test]
    fn into_iter() {
        let mut list = List::new();
        list.push(1);
        list.push(2);
        list.push(3);
        let mut iter = list.into_iter();
        assert_eq!(iter.next(), Some(3));
        assert_eq!(iter.next(), Some(2));
        assert_eq!(iter.next(), Some(1));
        // assert_eq!(iter.next(), None);
    }
}