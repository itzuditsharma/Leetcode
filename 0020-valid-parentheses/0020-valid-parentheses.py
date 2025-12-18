class Solution:
    def isValid(self, s: str) -> bool:
        mapp = {
            ')' : '(',
            '}' : '{',
            ']' : '['
        }
        stack = []
        for val in s:
            if val in mapp.values():
                stack.append(val)
            else:
                if not stack or stack[-1] != mapp[val]:
                    return False
                stack.pop()
        
        return len(stack) == 0