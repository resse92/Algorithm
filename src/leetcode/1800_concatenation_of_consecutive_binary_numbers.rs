use super::util::solution::Solution;

// https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/

impl Solution {
    pub fn concatenated_binary(n: i32) -> i32 {
        let mut ans = 0;
        let mut shift = 0;

        for i in 1..=n {
            if i & (i - 1) == 0 {
                shift += 1;
            }
            ans = ((ans << shift) + i) % 1_000_000_007;
        }
        ans
    }
}
