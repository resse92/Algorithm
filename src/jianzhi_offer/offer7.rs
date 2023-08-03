use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

struct Solution {}
impl Solution {
    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if preorder.is_empty() || inorder.is_empty() {
            return None;
        }

        let root = Rc::new(RefCell::new(TreeNode::new(preorder[0])));
        let index = inorder.iter().position(|&x| x == preorder[0]).unwrap();
        let left_preorder = preorder[1..index + 1].to_vec();
        let right_preorder = preorder[index + 1..].to_vec();

        let left_inorder = inorder[..index].to_vec();
        let right_inorder = inorder[index + 1..].to_vec();

        root.borrow_mut().left = Self::build_tree(left_preorder, left_inorder);
        root.borrow_mut().right = Self::build_tree(right_preorder, right_inorder);

        Some(root)
    }
}
