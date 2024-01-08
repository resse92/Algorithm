from typing import Optional

from util.python import ListNode

# https://leetcode.cn/problems/linked-list-cycle-ii/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        def hasCycle(head: ListNode):
            slow = head
            fast = head

            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next

                if slow == fast:
                    return True

            return False

        def findEntrance(head: ListNode):
            slow = head
            fast = head
            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next
                if slow == fast:
                    slow = head
                    while slow != fast:
                        slow = slow.next
                        fast = fast.next
                    return slow
            return None

        if not head or not head.next:
            return None

        if hasCycle(head):
            return findEntrance(head=head)
        else:
            return None
