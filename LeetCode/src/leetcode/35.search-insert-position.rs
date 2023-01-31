/*
 * @lc app=leetcode id=35 lang=rust
 *
 * [35] Search Insert Position
 */
use super::util::solution::Solution;
// @lc code=start
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        if nums.len() == 0 {
            return 0;
        }

        let mut high = nums.len(); // 4
        let mut low = 0; // 0
        while low < high {
            let mid = low + (high - low) / 2;
            if nums[mid] < target {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        low as i32
    }
}
// @lc code=end
