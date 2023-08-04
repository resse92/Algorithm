#
# @lc app=leetcode.cn id=1373 lang=python3
#
# [1373] 二叉搜索子树的最大键值和
#
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
# Definition for a binary tree node.


class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        maxSum = 0

        def helper(node: TreeNode):
            nonlocal maxSum
            if not node:
                return True, 0, float("inf"), float("-inf")
            isLeftBST, leftSum, leftMin, leftMax = helper(node.left)
            isRightBST, rightSum, rightMin, rightMax = helper(node.right)
            if isLeftBST and isRightBST and leftMax < node.val < rightMin:
                currSum = leftSum + rightSum + node.val
                maxSum = max(maxSum, currSum)
                return True, currSum, min(leftMin, node.val), max(rightMax, node.val)
            return False, 0, 0, 0

        helper(root)
        return maxSum


# @lc code=end
