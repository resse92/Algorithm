// https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

struct CQueue {
    head: Vec<i32>,
    tail: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl CQueue {
    fn new() -> Self {
        Self {
            head: vec![],
            tail: vec![],
        }
    }

    fn append_tail(&mut self, value: i32) {
        self.head.push(value)
    }

    fn delete_head(&mut self) -> i32 {
        if self.tail.is_empty() {
            while let Some(value) = self.tail.pop() {
                self.head.push(value);
            }
        }
        self.head.pop().unwrap_or(-1)
    }
}
