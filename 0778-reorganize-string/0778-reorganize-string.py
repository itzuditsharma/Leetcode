import heapq
class Solution:
    def reorganizeString(self, s: str) -> str:
        mapp = Counter(s)
        max_heap = [(-freq, key) for key, freq in mapp.items()]
        heapq.heapify(max_heap)
        prev = (0, "")

        result = ""
        while max_heap:
            freq, ch = heapq.heappop(max_heap)
            result += ch
            if prev[0] < 0:
                heapq.heappush(max_heap, prev)
            
            prev = (freq + 1, ch)
        
        return result if len(result) == len(s) else ""