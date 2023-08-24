use std::vec;

use super::util::solution::Solution;

// https://leetcode.cn/problems/count-servers-that-communicate/

impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        if m == 0 {
            return 0;
        }
        let n = grid[0].len();
        if n == 0 {
            return 0;
        }
        let mut column = vec![0; m];
        let mut row = vec![0; n];
        let mut count = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    column[i] += 1;
                    row[j] += 1;
                    count += 1;
                }
            }
        }
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 && (column[i] == 1 && row[j] == 1) {
                    count -= 1;
                }
            }
        }
        count
    }
}
