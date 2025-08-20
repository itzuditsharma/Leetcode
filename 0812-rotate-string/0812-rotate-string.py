class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        temp = s + s
        if goal in temp:
            return True
        return False



