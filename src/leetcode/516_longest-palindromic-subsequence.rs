/*
 * @lc app=leetcode id=516 lang=rust
 *
 * [516] Longest Palindromic Subsequence
 */

use super::util::solution::Solution;

// @lc code=start
impl Solution {
    pub fn longest_palindrome_subseq(s: String) -> i32 {
        let n = s.len();

        let mut res = vec![vec![0; s.len()]; s.len()];
        let chars: Vec<char> = s.chars().collect();

        for i in (0..n).rev() {
            res[i][i] = 1;
            for j in (i + 1)..n {
                if chars[i] == chars[j] {
                    res[i][j] = res[i + 1][j - 1] + 2
                } else {
                    res[i][j] = std::cmp::max(res[i + 1][j], res[i][j - 1])
                }
            }
        }
        res[0][n - 1]
    }
}
// @lc code=end
