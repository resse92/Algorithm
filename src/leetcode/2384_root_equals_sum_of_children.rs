use super::___58_length_of_last_word;
use super::util::solution::Solution;

use super::util::treenode::TreeNode;

// https://leetcode.cn/problems/root-equals-sum-of-children/

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn check_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root.is_none() {
            return true;
        }
        let root = root.unwrap();
        let root = root.borrow();
        if root.left.is_none() && root.right.is_none() {
            return false;
        }

        let left = root.left.as_ref().unwrap().borrow();
        let right = root.right.as_ref().unwrap().borrow();
        left.val + right.val == root.val
            && Solution::check_tree(root.left.clone())
            && Solution::check_tree(root.right.clone())
    }
}
