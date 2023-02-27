// https://github.com/jlkiri/rust-data-structures/tree/master/src

use std::mem;

struct Node<T> {
    value: T,
    next: Option<Box<Node<T>>>,
}

type Link<T> = Option<Box<Node<T>>>;

pub struct List<T> {
    head: Link<T>,
}

impl<T> List<T> {
    pub fn new() -> Self {
        List { head: None }
    }

    pub fn push(&mut self, item: T) {
        let next_node = Box::new(Node {
            value: item,
            next: self.head.take(),
        });

        self.head = Some(next_node)
    }

    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            node.value
        })
    }

    pub fn peek(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.value)
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
}