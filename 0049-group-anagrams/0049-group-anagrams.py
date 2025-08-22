class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        mapp = {}

        for x in strs:
            key = "".join(sorted(x))
            if key not in mapp:
                mapp[key] = []
            mapp[key].append(x)

        for key, val in mapp.items():
            ans.append(val)
        
        return ans