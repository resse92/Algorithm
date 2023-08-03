## 性能

### 遍历
```rust
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut size = 0;
        let mut index = 0;
        while index < nums.len() {
            if nums[index] != val {
                nums[size] = nums[index];
                size += 1;
            }
            index += 1;
        }

        return size as i32;
    }
}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut size = 0;

        for index in 0..nums.len() {
            if nums[index] == val {
                continue;
            }
            nums[size] = nums[index];
            size += 1;
        }

        return size as i32;
    }
}
```

以这一题为例，while循环比forin循环快