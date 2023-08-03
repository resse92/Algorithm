#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0
        l = 0
        r = len(height) - 1
        while l < r:
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l))
            if height[l] >= height[r]:
                r -= 1
            else:
                l += 1
        return maxArea
# @lc code=end

