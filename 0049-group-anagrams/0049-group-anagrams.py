class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapp = defaultdict(list)
        for word in strs:
            key = tuple(sorted(word))
            mapp[key].append(word)

        return list(mapp.values())