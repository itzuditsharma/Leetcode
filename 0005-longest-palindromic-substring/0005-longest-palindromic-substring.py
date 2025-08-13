class Solution:
    def get_palindrome(self, left, right, s, n):
        while left >= 0 and right < n and s[left] == s[right]:
            left-=1
            right += 1
        return s[left + 1: right]

    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        ans = ""

        for i in range(len(s)):
            # check for odd range string
            temp = self.get_palindrome(i, i, s, n)
            if len(temp) > len(ans):
                ans = temp

            # check for even range string
            temp = self.get_palindrome(i, i+1, s, n)
            if len(temp) > len(ans):
                ans = temp

        return ans