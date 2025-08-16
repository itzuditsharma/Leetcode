class Solution:
    def checkPalindrome(self, left, right, s, n):
        while left >=0 and right < n and s[left] == s[right]:
            left-=1
            right+=1
        return s[left+1:right]

    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        ans = ""

        for i in range(n):
            # Check for odd Palindromes
            temp = self.checkPalindrome(i, i, s, n)
            if len(temp) > len(ans):
                ans = temp
            # Check for even palindromes 
            temp = self.checkPalindrome(i, i+1, s, n)
            if len(temp) > len(ans):
                ans = temp

        return ans