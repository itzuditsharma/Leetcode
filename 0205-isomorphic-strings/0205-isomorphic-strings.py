class Solution:

    def generic_func(self,st1, st2, dicti):
        for i in range(len(st1)):
            t_val = st2[i]
            if dicti[st1[i]] != t_val:
                return False
        return True

    def isIsomorphic(self, s: str, t: str) -> bool:
        dicti1 = dict()
        for i in range(len(s)):
            dicti1[s[i]] = t[i]

        dicti2 = dict()
        for i in range(len(t)):
            dicti2[t[i]] = s[i]

        return self.generic_func(s,t,dicti1) and self.generic_func(t,s, dicti2)

        