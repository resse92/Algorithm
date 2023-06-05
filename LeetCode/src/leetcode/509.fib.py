#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#


# @lc code=start
class Solution:
    def fib(self, n: int) -> int:
        cache = {}

        def dfs(n: int) -> int:
            if n <= 1:
                return n
            if n in cache:
                return cache[n]
            cache[n] = dfs(n - 1) + dfs(n - 2)
            return cache[n]

        return dfs(n)


# @lc code=end
