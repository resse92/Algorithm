#
# @lc app=leetcode.cn id=1043 lang=python3
#
# [1043] 分隔数组以得到最大和
#

from typing import List


# @lc code=start
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        # 分隔数组以得到最大和, 滑动窗口python解法
        if not arr:
            return 0
        n = len(arr)
        dp = [0] * n
        for i in range(n):
            max_num = 0
            for j in range(1, k + 1):
                if i - (j - 1) < 0:
                    break
                max_num = max(max_num, arr[i - j + 1])
                if i - j >= 0:
                    dp[i] = max(dp[i], dp[i - j] + max_num * j)
                else:
                    dp[i] = max(dp[i], max_num * j)
        return dp[-1]


# @lc code=end
