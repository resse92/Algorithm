/*
 * @lc app=leetcode id=27 lang=rust
 *
 * [27] Remove Element
 */

// @lc code=start
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
// @lc code=end
