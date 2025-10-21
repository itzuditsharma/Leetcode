class Solution:
    def maxDepth(self, s: str) -> int:
        stack = []
        max_size = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(s[i])
                max_size = max(max_size, len(stack))
            elif s[i] == ')':
                stack.pop()

        return max_size