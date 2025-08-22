class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s_list = s.split()
        if len(pattern) != len(s_list):
            return False
        mapp = {}
        # ['dog', 'cat', 'cat', 'dog']
        for i in range(len(s_list)): 
            if mapp.get(s_list[i]) is not None:
                if mapp[s_list[i]] != pattern[i]:
                    return False
                else:
                    mapp[s_list[i]] = pattern[i]
            else:
                if pattern[i] in mapp.values():
                    return False
                mapp[s_list[i]] = pattern[i]

        return True