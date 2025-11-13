import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        max_vals = (heapq.nlargest(k, nums)) 
        return max_vals[-1]

