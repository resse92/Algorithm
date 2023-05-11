#
# @lc app=leetcode.cn id=1016 lang=python3
#
# [1016] 子串能表示从 1 到 N 数字的二进制串
#


# @lc code=start
class Solution:
    def queryString(self, s: str, n: int) -> bool:
        cache = {}
        for i in range(1, n + 1):
            if i not in cache:
                cache[i] = bin(i)[2:] in s
            if not cache[i]:
                return False
        return True


# @lc code=end
