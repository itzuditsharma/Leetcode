class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = nums[:k]
        heapq.heapify(heap)

        for elem in nums[k:]:
            heapq.heappush(heap, elem)
            if len(heap) > k:
                heapq.heappop(heap)

        return heap[0]