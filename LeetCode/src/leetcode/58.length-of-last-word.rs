/*
 * @lc app=leetcode id=58 lang=rust
 *
 * [58] Length of Last Word
 */

// @lc code=start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut size = s.len();
        let str = s.as_str();
        let mut length = 0;
        while size > 0 {
            size -= 1;
        }
        length
    }
}
// @lc code=end
