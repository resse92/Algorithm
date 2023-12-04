use super::util::solution::Solution;

// https://leetcode.cn/problems/array-with-elements-not-equal-to-average-of-neighbors/

impl Solution {
    pub fn rearrange_array(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort();
        let mut res = vec![0; 0];
        let mut l: usize = 0;
        let mut r = nums.len() - 1;

        while nums.len() > res.len() {
            res.push(nums[l]);
            l += 1;
            if l <= r {
                res.push(nums[r]);
                r -= 1;
            }
        }
        res
    }
}
