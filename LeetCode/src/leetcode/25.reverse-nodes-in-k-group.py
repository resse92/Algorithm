#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

from typing import Optional


class ListNode:
    def __init__(self, val=0, next: "ListNode" = None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        if self.next is None:
            return f"{self.val}"
        return f"{self.val}, {self.next}"


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 计算链表长度
        cur, length = head, 0
        while cur:
            length += 1
            cur = cur.next

        # 初始化哑节点和前驱节点
        dummy = ListNode(0)
        dummy.next, pre = head, dummy

        # 循环翻转每一组
        for i in range(length // k):
            cur = pre.next
            for j in range(k - 1):
                next = cur.next
                cur.next = next.next
                next.next = pre.next
                pre.next = next
            pre = cur

        return dummy.next


if __name__ == "__main__":
    solution = Solution()
    group = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    res = solution.reverseKGroup(group, 2)
    print(res)


# @lc code=end
