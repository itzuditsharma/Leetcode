# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))
        
        head = ListNode(0)
        temp = head

        while heap:
            val, i, node = heapq.heappop(heap)
            temp.next = node
            temp = temp.next
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))

        return head.next

