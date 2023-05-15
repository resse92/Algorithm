#
# @lc app=leetcode.cn id=1072 lang=python3
#
# [1072] 按列翻转得到最大值等行数
#
from typing import List


# @lc code=start
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        count = {}
        max_count = 0

        for row in matrix:
            if row[0] == 0:
                flipped_row = [1 - num for num in row]  # 翻转当前行
                count[tuple(flipped_row)] = count.get(tuple(flipped_row), 0) + 1
            else:
                count[tuple(row)] = count.get(tuple(row), 0) + 1

        for value in count.values():
            max_count = max(max_count, value)

        return max_count


# @lc code=end
