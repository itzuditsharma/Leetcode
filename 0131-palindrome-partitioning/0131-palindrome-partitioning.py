class Solution:
    def isValid(self, s, ind, i):
        return s[ind:i+1] == s[ind:i+1][::-1]

    def recur(self, ind, s, ans, path):
        if ind == len(s):
            ans.append(path[:])
            return 
        
        for i in range(ind, len(s)):
            if self.isValid(s, ind, i):
                path.append(s[ind:i+1])
                self.recur(i + 1, s, ans, path)
                path.pop()


    def partition(self, s: str) -> List[List[str]]:
        ans = []
        path = []
        n = len(s)
        self.recur(0, s, ans, path)
        return ans