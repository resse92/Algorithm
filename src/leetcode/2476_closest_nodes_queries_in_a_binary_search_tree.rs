use super::util::solution::Solution;

use super::util::treenode::TreeNode;

// https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/description/?envType=daily-question&envId=2024-02-24

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
    pub fn closest_nodes(root: Option<Rc<RefCell<TreeNode>>>, queries: Vec<i32>) -> Vec<Vec<i32>> {
        let n = queries.len();
        let mut ans = vec![vec![-1, -1]; n];
        let middle_order = Solution::middle_order(root);

        for (i, query) in queries.iter().enumerate() {
            let mut max_val = -1;
            let mut min_val = -1;
            // 二分查找最接近的数字
            let index = Solution::binary_search(&middle_order, *query);
            if index != middle_order.len() {
                max_val = middle_order[index];
                if middle_order[index] == *query {
                    min_val = middle_order[index];
                    ans[i] = vec![min_val, max_val];
                    continue;
                }
            }

            if index != 0 {
                min_val = middle_order[(index - 1) as usize];
            }
            ans[i] = vec![min_val, max_val];
        }

        ans
    }

    fn middle_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res = vec![];
        if let Some(node) = root {
            let node = node.borrow();
            res.append(&mut Solution::middle_order(node.left.clone()));
            res.push(node.val);
            res.append(&mut Solution::middle_order(node.right.clone()));
        }
        res
    }

    fn binary_search(arr: &Vec<i32>, target: i32) -> usize {
        let mut left: usize = 0;
        let mut right: usize = arr.len();
        while left < right {
            let mid = left + (right - left) / 2;
            if arr[mid] < target {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left
    }
}
