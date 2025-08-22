class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapp = {}

        for x in strs:
            key = "".join(sorted(x))
            if key not in mapp:
                mapp[key] = []
            mapp[key].append(x)

        return list(mapp.values())