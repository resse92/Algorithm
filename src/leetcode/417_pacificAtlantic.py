#
# @lc app=leetcode.cn id=417 lang=python3
#
# [417] 太平洋大西洋水流问题
#

from typing import List


# @lc code=start
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m = len(heights)
        if m == 0:
            return []
        n = len(heights[0])
        if n == 0:
            return []

        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]

        def dfs(i, j, visited):
            visited[i][j] = True
            for x, y in [[i - 1, j], [i, j - 1], [i, j + 1], [i + 1, j]]:
                if (
                    0 <= x < m
                    and 0 <= y < n
                    and not visited[x][y]
                    and heights[x][y] >= heights[i][j]
                ):
                    dfs(x, y, visited)

        for i in range(m):
            dfs(i, 0, pacific)
            dfs(i, n - 1, atlantic)
        for j in range(n):
            dfs(0, j, pacific)
            dfs(m - 1, j, atlantic)

        res = []
        for i in range(m):
            for j in range(n):
                if pacific[i][j] and atlantic[i][j]:
                    res.append([i, j])
        return res


# @lc code=end
