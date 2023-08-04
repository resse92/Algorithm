#
# @lc app=leetcode.cn id=1137 lang=python3
#
# [1137] 第 N 个泰波那契数
#


# @lc code=start
class Solution:
    def tribonacci(self, n: int) -> int:
        cache = {}

        def dfs(n: int) -> int:
            if n <= 0:
                return 0
            if n <= 1:
                return 1
            if n <= 2:
                return 1
            if n in cache:
                return cache[n]
            cache[n] = dfs(n - 1) + dfs(n - 2) + dfs(n - 3)
            return cache[n]

        return dfs(n)


# @lc code=end
