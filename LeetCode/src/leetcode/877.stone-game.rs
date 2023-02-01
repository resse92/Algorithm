/*
 * @lc app=leetcode id=877 lang=rust
 *
 * [877] Stone Game
 */
use super::util::solution::Solution;

// @lc code=start
impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        let n = piles.len();
        let mut res = vec![vec![(0, 0); n]; n];
        for i in 0..n {
            res[i][i] = (piles[i], 0);
        }
        for i in 1..(n - 1) {
            for j in i..n {
                let left = piles[i] + res[i + 1][j].1; // 从左边拿
                let right = piles[j] + res[i][j - 1].1; // 从右边拿
                if left > right {
                    res[i][j].0 = left;
                    res[i][j].1 = res[i + 1][j].0;
                } else {
                    res[i][j].0 = right;
                    res[i][j].1 = res[i][j - 1].0;
                }
            }
        }
        let pair = res[0][n - 1];
        pair.0 >= pair.1
    }
}
// @lc code=end
