class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        if len(cardPoints) == k:
            return sum(cardPoints)
        n = len(cardPoints)
        lsum = 0
        rsum = 0
        for i in range(k):
            lsum += cardPoints[i]

        r = n-1 
        l = k-1
        maxsum = lsum

        while l >= 0:
            lsum -= cardPoints[l]
            rsum += cardPoints[r]
            maxsum = max(maxsum, lsum + rsum)
            l-=1
            r-=1
        
        return maxsum