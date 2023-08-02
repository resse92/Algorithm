/*
 * @lc app=leetcode.cn id=54 lang=rust
 *
 * [54] spiral_order
 */

use super::util::solution::Solution;

// @lc code=start
impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        if matrix.is_empty() || matrix[0].is_empty() {
            return vec![];
        }

        let m = matrix.len(); // row count
        let n = matrix[0].len(); // column count
        let total = m * n; // total numbers in matrix
        let mut result = Vec::with_capacity(total);

        let mut left = 0;
        let mut right = n - 1;
        let mut top = 0;
        let mut bottom = m - 1;

        while result.len() < total {
            for j in left..=right {
                result.push(matrix[top][j]);
            }
            top += 1;

            if result.len() < total {
                for i in top..=bottom {
                    result.push(matrix[i][right]);
                }
                right -= 1;
            }

            if result.len() < total {
                for j in (left..=right).rev() {
                    result.push(matrix[bottom][j]);
                }
                bottom -= 1;
            }

            if result.len() < total {
                for i in (top..=bottom).rev() {
                    result.push(matrix[i][left]);
                }
                left += 1;
            }
        }

        result
    }
}
// @lc code=end
