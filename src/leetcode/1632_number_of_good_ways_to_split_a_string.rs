use super::util::solution::Solution;

// https://leetcode.cn/problems/number-of-good-ways-to-split-a-string/

impl Solution {
    pub fn num_splits(s: String) -> i32 {
        let mut left = vec![0; 26];
        let mut right = vec![0; 26];
        let mut left_count = 0;
        let mut right_count = 0;
        let mut result = 0;
        for c in s.chars() {
            let index = (c as u8 - 'a' as u8) as usize;
            if right[index] == 0 {
                right_count += 1;
            }
            right[index] += 1;
        }
        for c in s.chars() {
            let index = (c as u8 - 'a' as u8) as usize;
            if left[index] == 0 {
                left_count += 1;
            }
            left[index] += 1;
            right[index] -= 1;
            if right[index] == 0 {
                right_count -= 1;
            }
            if left_count == right_count {
                result += 1;
            }
        }
        result
    }
}
