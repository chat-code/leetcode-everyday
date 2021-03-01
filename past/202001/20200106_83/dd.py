# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        old_head = head
        while head and head.next:
            if head.val == head.next.val:
                if head.next.next:
                    head.next = head.next.next
                else:
                    head.next = None
            else:
                head = head.next
        return old_head
