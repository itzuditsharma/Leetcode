class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = ""
        stack = []

        for ch in s:
            if ch == '(':
                if len(stack) != 0:
                    ans += ch
                stack.append(ch)
            else:
                stack.pop()
                if len(stack) != 0:
                    ans += ch
            
        return ans