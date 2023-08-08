use super::util::solution::Solution;

// https://leetcode.cn/problems/number-of-islands/

impl Solution {
    // 深度优先，遇到一个岛，就把这个岛上所有陆地标记为已访问（即置为0），然后继续遍历
    fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize) {
        if i >= grid.len() || j >= grid[i].len() || grid[i][j] == '0' {
            return;
        }
        grid[i][j] = '0';
        Self::dfs(grid, i - 1, j);
        Self::dfs(grid, i + 1, j);
        Self::dfs(grid, i, j - 1);
        Self::dfs(grid, i, j + 1);
    }

    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let mut grid = grid;
        let mut count = 0;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == '1' {
                    count += 1;
                    Self::dfs(&mut grid, i, j);
                }
            }
        }
        count
    }
}
