use super::util::solution::Solution;

// https://leetcode.cn/problems/two-sum/

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = std::collections::HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            let diff = target - num;
            if let Some(&j) = map.get(&diff) {
                return vec![i as i32, j as i32];
            }
            map.insert(num, i);
        }
        vec![]
    }
}
