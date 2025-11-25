class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        maxHeap = []
        
        for num in arr:
            heapq.heappush(maxHeap, (-abs(num - x), -num))  # simulate max-heap
            if len(maxHeap) > k:
                heapq.heappop(maxHeap)
        
        result = [-item[1] for item in maxHeap]
        return sorted(result)
