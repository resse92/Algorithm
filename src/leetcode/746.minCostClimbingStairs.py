#
# @lc app=leetcode.cn id=746 lang=python3
#
# [746] 使用最小花费爬楼梯
#
from typing import List


# @lc code=start
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cache = {}
        n = len(cost)

        def dfs(n: int) -> int:
            if n <= 1:
                return 0
            if n in cache:
                return cache[n]
            cache[n] = min(dfs(n - 1) + cost[n - 1], dfs(n - 2) + cost[n - 2])
            return cache[n]

        return dfs(n)


# @lc code=end
