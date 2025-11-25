class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        maxHeap = [(-abs(i-x), -i) for i in arr]
        heapq.heapify(maxHeap)
        for i in range(len(arr) - k):
            heapq.heappop(maxHeap)

        return sorted(-i[1] for i in maxHeap)
