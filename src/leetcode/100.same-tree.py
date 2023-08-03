#
# @lc app=leetcode id=100 lang=python3
#
# [100] Same Tree
#

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:        
        def rec(p, q):
            if p and q:
                return p.val == q.val and rec(p.left, q.left) and rec(p.right, q.right)
            elif p or q:
                return False
            return True

        return rec(p, q)


# @lc code=end
