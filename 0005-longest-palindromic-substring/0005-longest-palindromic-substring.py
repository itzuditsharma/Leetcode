class Solution:
    def checkPalindrome(self, left, right, s):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1: right]

    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        ans = ""

        for i in range(len(s)):
            temp = self.checkPalindrome(i, i, s)
            if len(temp) > len(ans):
                ans = temp
            
            temp = self.checkPalindrome(i, i+1, s)
            if len(temp) > len(ans):
                ans = temp
        
        return ans