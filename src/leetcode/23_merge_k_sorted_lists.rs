use std::borrow::Borrow;

use super::util::solution::Solution;

use super::util::listnode::ListNode;

// https://leetcode.cn/problems/merge-k-sorted-lists/description/

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut lists = lists;
        let mut result = None;
        let mut result_tail = &mut result;
        loop {
            let mut min_index = None;
            for (i, list) in lists.iter().enumerate() {
                if list.is_none() {
                    continue;
                }
                if min_index.is_none() {
                    min_index = Some(i);
                    continue;
                }
                if list.as_ref().unwrap().val < lists[min_index.unwrap()].as_ref().unwrap().val {
                    min_index = Some(i);
                }
            }
            if min_index.is_none() {
                break;
            }
            let min_index = min_index.unwrap();
            let mut min_node = lists[min_index].take().unwrap();

            lists[min_index] = min_node.next.take();
            if result_tail.is_none() {
                *result_tail = Some(min_node);
            } else {
                result_tail.as_mut().unwrap().next = Some(min_node);
                result_tail = &mut result_tail.as_mut().unwrap().next;
            }
        }
        result
    }
}

use std::cmp::Ordering;
use std::collections::BinaryHeap;

// 定义一个新的结构体，用于存储链表节点的值和索引
#[derive(Eq, PartialEq)]
struct Node {
    value: i32,
    index: usize,
    next: Option<Box<ListNode>>,
}

// 实现 Ord trait，使得 BinaryHeap 可以对 Node 进行排序
impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.value.cmp(&self.value)
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// 优先队列(最大堆最小堆)是一种数据结构，它可以在任何时候找到队列中的最小（或最大）元素。
// 在这个问题中，我们可以使用优先队列来存储所有链表的当前节点，然后每次从优先队列中取出最小的节点。
fn merge_k_lists2(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    let mut result = Box::new(ListNode::new(0));
    let mut result_tail = &mut result;
    let mut heap = BinaryHeap::new();

    // 将所有链表的第一个节点添加到堆中
    for (i, list) in lists.into_iter().enumerate() {
        if let Some(mut node) = list {
            let next = node.next.take();
            heap.push(Node {
                value: node.val,
                index: i,
                next,
            });
        }
    }

    while let Some(Node {
        value,
        index,
        mut next,
    }) = heap.pop()
    {
        // 将当前最小的节点添加到结果链表的末尾
        result_tail.next = Some(Box::new(ListNode::new(value)));
        result_tail = result_tail.next.as_mut().unwrap();

        // 将当前链表的下一个节点添加到堆中
        if let Some(mut node) = next.take() {
            let next = node.next.take();
            heap.push(Node {
                value: node.val,
                index,
                next,
            });
        }
    }

    result.next
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_merge_k_lists() {
        let mut list1 = Some(Box::new(ListNode::new(1)));
        list1.as_mut().unwrap().next = Some(Box::new(ListNode::new(4)));
        list1.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(5)));

        let mut list2 = Some(Box::new(ListNode::new(1)));
        list2.as_mut().unwrap().next = Some(Box::new(ListNode::new(3)));
        list2.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(4)));

        let mut list3 = Some(Box::new(ListNode::new(2)));
        list3.as_mut().unwrap().next = Some(Box::new(ListNode::new(6)));

        let lists = vec![list1, list2, list3];

        let mut expected = Some(Box::new(ListNode::new(1)));
        expected.as_mut().unwrap().next = Some(Box::new(ListNode::new(1)));
        expected.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(2)));
        expected
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next = Some(Box::new(ListNode::new(3)));
        expected
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next = Some(Box::new(ListNode::new(4)));
        expected
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next = Some(Box::new(ListNode::new(4)));
        expected
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next = Some(Box::new(ListNode::new(5)));
        expected
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next
            .as_mut()
            .unwrap()
            .next = Some(Box::new(ListNode::new(6)));

        assert_eq!(Solution::merge_k_lists(lists), expected);
    }
}
