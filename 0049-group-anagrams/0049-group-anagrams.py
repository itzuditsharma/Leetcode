class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapp = {}
        for item in strs:
            key = "".join(sorted(item))
            if key not in mapp:
                mapp[key] = []
            mapp[key].append(item)
        
        return list(mapp.values())