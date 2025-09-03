class Solution:
    def maxSlidingWindow(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        ans = [0] * (n-k+1)

        for i in range(n-k+1):
            ans[i] = max(arr[i: i + k])
        
        return ans
