class Solution:
    def maxDepth(self, s: str) -> int:
        maxlen = 0
        stack = []

        for ch in s:
            if ch == '(':
                stack.append(ch)
                maxlen = max(maxlen, len(stack))
            elif ch == ')':
                stack.pop()
        
        return maxlen