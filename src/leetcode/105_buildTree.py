# Definition for a binary tree node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import List, Optional

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def helper(in_left = 0, in_right = len(inorder)):
            nonlocal pre_idx
            if in_left == in_right:
                return None

            root_val = preorder[pre_idx]
            root = TreeNode(root_val)

            index = idx_map[root_val]

            pre_idx += 1

            root.left = helper(in_left, index)
            root.right = helper(index + 1, in_right)
            return root

        pre_idx = 0
        idx_map = {val:idx for idx, val in enumerate(inorder)}
        return helper()

    def buildTreeV2(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None
        root_val = preorder.pop()
        node = TreeNode(root_val)
        inorder_index = inorder.index(root_val)
        node.left = self.buildTreeV2(preorder, inorder[0:inorder_index])
        node.right = self.buildTreeV2(preorder, inorder[inorder_index+1:])
        return node

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        results = []
        if root.left is not None:
            results.extend(self.inorderTraversal(root.left))

        results.append(root.val)

        if root.right is not None:
            results.extend(self.inorderTraversal(root.right))

        return results

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        results = []
        results.append(root.val)

        results.extend(self.preorderTraversal(root.left))
        results.extend(self.preorderTraversal(root.right))

        return results
