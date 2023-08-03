/*
 * @lc app=leetcode id=740 lang=rust
 *
 * [740] Delete and Earn
 */
use super::util::solution::Solution;

// @lc code=start
impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut max_val = 0;
        for &num in nums.iter() {
            max_val = max_val.max(num);
        }
        // 创建一个数组，数组index表明nums[i]的值，数组值表明nums[i]的和
        let mut sum = vec![0; max_val as usize + 1];
        // 计算nums[i]的和
        for &num in nums.iter() {
            sum[num as usize] += num;
        }
        // 动态规划
        let mut dp = vec![0; max_val as usize + 1];
        dp[1] = sum[1];
        // dp[i] = max(dp[i-1], dp[i-2] + sum[i])
        for i in 2..=max_val as usize {
            dp[i] = dp[i - 1].max(dp[i - 2] + sum[i]);
        }
        dp[max_val as usize]
    }
}
// @lc code=end
