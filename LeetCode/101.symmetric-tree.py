#
# @lc app=leetcode id=101 lang=python3
#
# [101] Symmetric Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def mirror(left: TreeNode, right: TreeNode) -> bool:
            if left and right:
                return (
                    left.val == right.val
                    and mirror(left.left, right.right)
                    and mirror(left.right, right.left)
                )
            elif left or right:
                return False
            return True

        return not root or mirror(root.left, root.right)


# @lc code=end
