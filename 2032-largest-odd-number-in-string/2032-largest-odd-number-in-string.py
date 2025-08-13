class Solution:
    def largestOddNumber(self, num: str) -> str:
        n = len(num)

        if int(num[n-1]) %2 == 1:
            return num
        i = n-1
        while i >=0:
            if int(num[i]) %2 == 0:
                i-=1
            else:
                return num[0:i+1]
        
        return ""
