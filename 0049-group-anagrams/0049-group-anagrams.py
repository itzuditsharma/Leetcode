class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        n = len(strs)
        mapp = {}

        for s in strs:
            key = "".join(sorted(s))
            if key not in mapp.keys():
                mapp[key] = []
            mapp[key].append(s)

        return list(mapp.values())