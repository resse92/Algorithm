use super::util::solution::Solution;

use super::util::treenode::TreeNode;

// https://leetcode.cn/problems/sum-root-to-leaf-numbers/

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
    fn _dfs(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> i32 {
        if let Some(v) = root {
            let v = v.borrow();
            let sum = sum * 10 + v.val;
            if v.left.is_none() && v.right.is_none() {
                return sum;
            }
            return Self::_dfs(v.left.clone(), sum) + Self::_dfs(v.right.clone(), sum);
        }
        0
    }
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::_dfs(root, 0)
    }
}
