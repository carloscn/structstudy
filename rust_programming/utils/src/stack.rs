use std::ops::{self, Add};
use std::convert::From;

pub struct Stack<T> {
    stack: Vec<T>,
}

impl<T:std::fmt::Debug + ops::Add + Copy> Stack<T>
{
    pub fn new() -> Self {
        Stack { stack:Vec::new() }
    }

    pub fn pop(&mut self) -> T {
        self.stack.remove(self.len() - 1)
    }

    pub fn push(&mut self, item: T) {
        self.stack.push(item)
    }

    pub fn is_empty(&self) -> bool {
        self.stack.is_empty()
    }

    pub fn len(&self) -> usize {
        self.stack.len()
    }

    pub fn peek(&self) -> Option<&T> {
        self.stack.last()
    }

    pub fn sum(&self) -> T
    where T:ops::Add<Output = T> + From<i64>{
        let mut sum = T::from(0);
        for e in &self.stack {
            sum = sum + *e;
        }
        return sum;
    }

    pub fn dup_vector(&self) -> Vec<T>
    where T:Copy {
        let mut v_e:Vec<T> = vec![];

        for e in &self.stack {
            v_e.push(*e);
        }
        return v_e;
    }


    pub fn clear(&mut self) {
        self.stack.truncate(0);
    }

    pub fn print(&self) {
        print!("stack : {:?}\n", self.stack);
    }

}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_stack() {
        let mut stack: Stack<isize> = Stack::new();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        let item = stack.pop();
        assert_eq!(stack.is_empty(), false);
        assert_eq!(item, 3);

        stack.clear();
        assert_eq!(stack.len(), 0);
        assert_eq!(stack.is_empty(), true);
    }
}