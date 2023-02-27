pub struct Queue<T> {
    queue:Vec<T>,
}

impl<T> Queue<T> {
    pub fn new() -> Self {
        Queue {queue: Vec::new()}
    }

    pub fn len(&self) -> usize {
        self.queue.len()
    }

    pub fn push(&mut self, item: T) {
        self.queue.push(item)
    }

    pub fn pop(&mut self) -> T {
        self.queue.remove(0)
    }

    pub fn is_empty(&self) -> bool {
        self.queue.is_empty()
    }

    pub fn peek(&self) -> Option<&T> {
        self.queue.first()
    }

    pub fn clear(&mut self) {
        self.queue.truncate(0)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_queue() {
        let mut queue: Queue<isize> = Queue::new();
        queue.push(1);
        queue.push(2);
        queue.push(3);
        let item = queue.pop();
        assert_eq!(queue.is_empty(), false);
        assert_eq!(item, 1);

        queue.clear();
        assert_eq!(queue.len(), 0);
        assert_eq!(queue.is_empty(), true);
    }
}