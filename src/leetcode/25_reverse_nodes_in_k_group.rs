/*
 * @lc app=leetcode id=25 lang=rust
 *
 * [25] Reverse Nodes in k-Group
 */

use super::util::link_list::ListNode;
use super::util::solution::Solution;

// @lc code=start
// Definition for singly-linked list.

impl Solution {
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        // 创建一个虚拟head，最后返回head.next
        let mut dummy_head = Some(Box::new(ListNode { val: 0, next: head }));
        let mut head = dummy_head.as_mut();

        'outer: loop {
            // 保存next
            let mut start = head.as_mut().unwrap().next.take();
            if start.is_none() {
                break 'outer;
            }

            let mut end = start.as_mut();
            // 找到k个尾结点，如果找不到，则说明链表长度不够，break
            for _ in 0..(k - 1) {
                end = end.unwrap().next.as_mut();
                if end.is_none() {
                    head.as_mut().unwrap().next = start;
                    break 'outer;
                }
            }
            // 尾结点next
            let tail = end.as_mut().unwrap().next.take();
            let end = Solution::reverse(start, tail);
            head.as_mut().unwrap().next = end;
            for _ in 0..k {
                head = head.unwrap().next.as_mut()
            }
        }

        dummy_head.unwrap().next
    }

    #[inline(always)]
    fn reverse(head: Option<Box<ListNode>>, tail: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut prev = tail;
        let mut cur = head;
        while let Some(mut cur_node_inner) = cur {
            let next = cur_node_inner.next.take();
            cur_node_inner.next = prev.take();
            prev = Some(cur_node_inner);
            cur = next;
        }
        prev
    }
}
// @lc code=end
