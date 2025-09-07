class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapp = defaultdict(list)
        for item in strs:
            key = "".join(sorted(item))
            mapp[key].append(item)
        
        return list(mapp.values())