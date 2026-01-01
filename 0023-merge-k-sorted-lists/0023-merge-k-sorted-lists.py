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
                heapq.heappush(heap, (lists[i].val, i, lists[i]))
                
        dummyNode = ListNode(-1)
        temp = dummyNode

        while heap:
            elem, list_idx, node = heapq.heappop(heap)
            temp.next = node
            temp = temp.next
            if node.next != None:
                heapq.heappush(heap, (node.next.val, list_idx, node.next))
        
        return dummyNode.next