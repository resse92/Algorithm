use super::util::solution::Solution;

// https://leetcode.cn/problems/permutations/

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res = vec![];
        let mut path = vec![];
        let mut used = vec![false; nums.len()];

        Self::_backtrack(&nums, &mut res, &mut path, &mut used);
        res
    }

    fn _backtrack(
        nums: &Vec<i32>,
        res: &mut Vec<Vec<i32>>,
        path: &mut Vec<i32>,
        used: &mut Vec<bool>,
    ) {
        if path.len() == nums.len() {
            res.push(path.clone());
            return;
        }
        for i in 0..nums.len() {
            if used[i] {
                continue;
            }
            path.push(nums[i]);
            used[i] = true;
            Self::_backtrack(nums, res, path, used);
            path.pop();
            used[i] = false;
        }
    }
}
