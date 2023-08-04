#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
# Definition for a binary tree node.


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        def inorder(_list: List[int], root):
            if root.left is not None:
                inorder(_list, root.left)
            _list.append(root.val)
            if root.right is not None:
                inorder(_list, root.right)
            return _list

        if root is None:
            return []
        return inorder([], root)


# @lc code=end
