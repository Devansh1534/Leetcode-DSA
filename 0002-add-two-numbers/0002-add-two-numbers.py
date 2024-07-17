# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode(0)
        curr = dummy
        carr = 0

        while l1 or l2:
            x=l1.val if l1 else 0
            y=l2.val if l2 else 0
            tot= x+y+carr
            carr=tot//10
            curr.next=ListNode(tot % 10)

            if l1:
                l1=l1.next
            if l2:
                l2=l2.next
            curr = curr.next
            if carr>0:
                curr.next=ListNode(carr)

        return dummy.next        