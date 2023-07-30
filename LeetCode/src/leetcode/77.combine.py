#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#
from typing import List


# @lc code=start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        """
        深度优先搜索
        从第一个开始，每次加入一个数，直到长度为k
        然后推出最后一个数，加入下一个数，直到长度为k
        事件复杂度：O(n^k)
        """
        res = []

        def dfs(start, path):
            if len(path) == k:
                res.append(path)
                return
            for i in range(start, n + 1):
                path.append(i)
                dfs(i + 1, path)
                path.pop()

        dfs(1, [])
        return res

    def combin2(self, n: int, k: int) -> List[List[int]]:
        """
        位运算法
        时间复杂度: O(n^2)
        思路:
        1. 生成一个n位的二进制数,每一位代表一个数是否被选中
        2. 从1开始,每次加1,直到2^n
        3. 每次加1后,判断二进制数中1的个数是否为k,是则加入结果集
        """
        s = 1 << n
        res = []
        for i in range(s):
            path = []
            for j in range(n):
                if i & (1 << j):
                    path.append(j + 1)
            if len(path) == k:
                res.append(path)
        return res


# @lc code=end
