class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapp = defaultdict(list)

        for word in strs:
            sorted_word = "".join(sorted(word))
            mapp[sorted_word].append(word)
        
        return list(mapp.values())