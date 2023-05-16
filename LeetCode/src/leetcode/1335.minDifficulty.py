#
# @lc app=leetcode.cn id=1335 lang=python3
#
# [1335] 工作计划的最低难度
#

from typing import List


# @lc code=start
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)

        if n < d:
            return -1

        dp = [[float("inf")] * (d + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(1, n + 1):
            for k in range(1, min(i, d) + 1):
                max_difficulty = 0
                for j in range(i - 1, k - 2, -1):
                    max_difficulty = max(max_difficulty, jobDifficulty[j])
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + max_difficulty)

            return dp[n][d] if dp[n][d] != float("inf") else -1


# @lc code=end
