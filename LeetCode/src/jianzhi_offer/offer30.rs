struct MinStack {
    min: i32,
    stack: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {
    /** initialize your data structure here. */
    fn new() -> Self {
        Self {
            min: i32::MAX,
            stack: Vec::new(),
        }
    }

    fn push(&mut self, x: i32) {
        self.min = std::cmp::min(x, self.min);
        self.stack.push(x);
    }

    fn pop(&mut self) {
        self.stack.pop();
        self.min = i32::MAX;
        for i in 0..self.stack.len() {
            self.min = std::cmp::min(self.stack[i], self.min);
        }
    }

    fn top(&self) -> i32 {
        self.stack[self.stack.len() - 1]
    }

    fn min(&self) -> i32 {
        self.min
    }
}
