#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#


# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        cache = {}

        def dfs(n: int) -> int:
            if n <= 1:
                return 1
            if n <= 2:
                return 2
            if n in cache:
                return cache[n]
            cache[n] = dfs(n - 1) + dfs(n - 2)
            return cache[n]

        return dfs(n)


# @lc code=end
