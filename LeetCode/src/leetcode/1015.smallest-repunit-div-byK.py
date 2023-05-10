#
# @lc app=leetcode.cn id=1015 lang=python3
#
# [1015] 可被 K 整除的最小整数
#


# @lc code=start
class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1
        n = 1
        for i in range(1, k + 1):
            if n % k == 0:
                return i
            n = (n * 10 + 1) % k
        return -1


# @lc code=end
