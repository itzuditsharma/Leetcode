class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = ""
        stack = []

        for i in range(len(s)):
            if s[i] == '(':
                if len(stack) != 0:
                    ans+=(s[i])
                stack.append(s[i])
            else:
                stack.pop()
                if len(stack) != 0:
                    ans+=(s[i])

        return ans