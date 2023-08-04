#
# @lc app=leetcode.cn id=1130 lang=python3
#
# [1130] 叶值的最小代价生成树
#
from typing import List


# @lc code=start
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        # 单调栈
        # 1. 从左到右遍历数组，维护一个单调递减栈
        # 2. 如果当前元素大于栈顶元素，则栈顶元素出栈，计算栈顶元素与当前元素的乘积，加入到结果中
        # 3. 如果当前元素小于栈顶元素，则当前元素入栈
        # 4. 遍历完成后，如果栈中元素大于1，则依次出栈，计算栈顶元素与栈顶下一个元素的乘积，加入到结果中
        # 5. 返回结果
        stack = [float("inf")]
        res = 0
        for num in arr:
            while stack[-1] <= num:
                mid = stack.pop()
                res += mid * min(stack[-1], num)
            stack.append(num)
        while len(stack) > 2:
            res += stack.pop() * stack[-1]
        return res


# @lc code=end
