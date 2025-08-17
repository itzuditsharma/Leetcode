class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        n = len(strs)
        mapp = {}

        for it in strs:
            key = "".join(sorted(it))
            if key not in mapp:
                mapp[key] = []
            mapp[key].append(it)

        return list(mapp.values())