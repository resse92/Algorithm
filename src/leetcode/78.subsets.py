#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

from typing import List

# 思路: 位运算
# 1. 用二进制表示每个元素是否在子集中
# 2. 用位运算判断每个元素是否在子集中
# 3. 用位运算生成所有子集
# 4. 用位运算生成所有子集的代码


# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        # 1 << n: 2^n, 表示所有子集的个数
        for i in range(1 << n):
            subset = []
            for j in range(n):
                # 1 << j: 2^j, 表示第j个元素是否在子集中
                if i & (1 << j):
                    subset.append(nums[j])
            res.append(subset)
        return res


# @lc code=end
