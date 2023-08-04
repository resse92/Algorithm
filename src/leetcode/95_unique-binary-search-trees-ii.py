#
# @lc app=leetcode id=95 lang=python3
#
# [95] Unique Binary Search Trees II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []
        memo = {}
        return self.helper(1, n, memo)

    def helper(self, start: int, end: int, memo: {(int, int): [int]}) -> List[TreeNode]:
        if start > end:
            return [None]
        result = []
        for i in range(start, end + 1):
            left = []
            if (start, i - 1) in memo:
                left = memo[(start, i - 1)]
            else:
                left = self.helper(start, i - 1, memo)
                memo[(start, i - 1)] = left

            right = []
            if (i + 1, end) in right:
                right = memo[(i + 1, end)]
            else:
                right = self.helper(i + 1, end, memo)
                memo[(i + 1, end)] = right
            for a in left:
                for b in right:
                    node = TreeNode(i)
                    node.left = a
                    node.right = b
                    result.append(node)
        return result


# @lc code=end
