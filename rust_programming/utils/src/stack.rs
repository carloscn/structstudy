
pub struct Stack<T> {
    stack: Vec<T>,
}

impl<T> Stack<T> {
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

    pub fn clear(&mut self) {
        self.stack.truncate(0);
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