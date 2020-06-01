#
# @lc app=leetcode id=102 lang=python3
#
# [102] Binary Tree Level Order Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = [[]]
        curr_nodes = [root]
        next_nodes = []
        while len(curr_nodes) != 0:
            node = curr_nodes.pop(0)
            if node:
                if node.left:
                    next_nodes.append(node.left)
                if node.right:
                    next_nodes.append(node.right)
                res[-1].append(node.val)
            if len(curr_nodes) == 0 and len(next_nodes):
                curr_nodes = next_nodes
                next_nodes = []
                res.append([])

        return res


# @lc code=end
