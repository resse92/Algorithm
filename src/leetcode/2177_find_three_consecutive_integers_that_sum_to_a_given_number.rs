use super::util::solution::Solution;

// https://leetcode.cn/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/

impl Solution {
    pub fn sum_of_three(num: i64) -> Vec<i64> {
        if num % 3 == 0 {
            let middle = num / 3;
            return vec![middle - 1, middle, middle + 1];
        }

        vec![]
    }
}
