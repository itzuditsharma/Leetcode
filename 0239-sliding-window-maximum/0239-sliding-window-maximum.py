from collections import deque
class Solution:
    def maxSlidingWindow(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        max_list = []
        dq = deque()
        for i in range(n):
            while dq and dq[0] <= i-k:
                dq.popleft()

            while dq and arr[dq[-1]] <= arr[i]:
                dq.pop()

            dq.append(i)
            
            if i >= k-1:
                max_list.append(arr[dq[0]])

        return max_list
