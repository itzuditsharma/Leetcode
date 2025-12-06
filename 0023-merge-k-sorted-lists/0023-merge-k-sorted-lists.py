# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val,i, lists[i]))

        heapq.heapify(heap)
        temp_node = ListNode(-1)
        temp = temp_node

        while heap:
            elem, i, node = heapq.heappop(heap)
            temp.next = node
            temp = temp.next

            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))
        
        return temp_node.next