class Solution:
    def isValid(self, s: str) -> bool:
        dicti = {
            ")" : "(",
            "]" : "[",
            "}" : "{"
        }
        stack = []
        n = len(s)

        for char in s:
            if char in dicti.values():
                stack.append(char)
            elif char in dicti.keys():
                if not stack or stack[-1] != dicti[char]:
                    return False
                stack.pop()
            else:
                return False

        if len(stack) == 0:
            return True
        else:
            return False
