#
# @lc app=leetcode.cn id=1187 lang=python3
#
# [1187] 使数组严格递增
#
from typing import List
from bisect import bisect_right


# @lc code=start
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        n = len(arr1)
        arr2 = sorted(set(arr2))
        m = len(arr2)
        dp = {(arr1[0], -1): 0, (-1, 0): 1}
        for i in range(1, n):
            new_dp = {}
            for (x, y), cnt in dp.items():
                if arr1[i] > x:
                    new_dp[(arr1[i], y)] = min(
                        new_dp.get((arr1[i], y), float("inf")), cnt
                    )
                j = bisect_right(arr2, y)
                if j < m:
                    new_dp[(x, arr2[j])] = min(
                        new_dp.get((x, arr2[j]), float("inf")), cnt + 1
                    )
            dp = new_dp
        ans = min(
            dp.get((arr1[n - 1], -1), float("inf")),
            dp.get((-1, arr2[m - 1]), float("inf")),
        )
        return ans if ans < float("inf") else -1


# @lc code=end
