use super::util::solution::Solution;
use super::util::treenode::TreeNode;

// https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn minimum_operations(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }
        let root = root.unwrap();
        let mut queue = vec![root];
        let mut ans = 0;
        while !queue.is_empty() {
            let mut next_queue = vec![];
            let mut values = vec![];
            for node in queue {
                let node = node.borrow();
                values.push(node.val);
                if node.left.is_some() {
                    next_queue.push(Rc::clone(&node.left.as_ref().unwrap()));
                }
                if node.right.is_some() {
                    next_queue.push(Rc::clone(&node.right.as_ref().unwrap()));
                }
            }

            // values进行离散化
            let mut sorted_values = values.clone();
            sorted_values.sort();
            let mut map = std::collections::HashMap::new();
            for (i, v) in sorted_values.iter().enumerate() {
                map.insert(v, i);
            }

            let values = values.iter().map(|v| map[v]).collect::<Vec<_>>();

            // 置换环
            let mut count = 0;
            let mut flags = vec![false; values.len()];
            for i in 0..values.len() {
                if flags[i] {
                    continue;
                }
                // 按顺序找节点，直到找到一个环
                let mut j = i;
                while !flags[j] {
                    flags[j] = true;
                    j = values[j];
                }
                // 环的个数+1
                count += 1;
            }
            // values的长度减去环的个数就是需要置换的次数
            ans += values.len() as i32 - count;

            queue = next_queue;
        }
        ans
    }
}
