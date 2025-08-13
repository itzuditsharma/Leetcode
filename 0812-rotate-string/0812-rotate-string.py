class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        for i in range(len(s)):
            left = s[0:i]
            right = s[i:]
            if right + left == goal:
                return True
            
        return False