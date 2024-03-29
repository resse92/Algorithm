/*
 * @lc app=leetcode id=58 lang=rust
 *
 * [58] Length of Last Word
 */
use super::util::solution::Solution;
// @lc code=start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut size = s.len();
        let length = 0;
        while size > 0 {
            size -= 1;
        }
        length
    }
}
// @lc code=end
