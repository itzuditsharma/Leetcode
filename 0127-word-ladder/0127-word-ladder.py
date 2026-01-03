class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        sett = set(wordList)
        q = deque()
        q.append((beginWord, 1))
        sett.discard(beginWord)   
        # sett.remove(beginWord) #leads to an error if element not present in set   

        while q:
            word, steps = q.popleft()
            if word == endWord:
                return steps
            
            for i in range(len(word)):
                for c in string.ascii_lowercase:
                    new_word = word[:i] + c + word[i+1:]
                    if new_word in sett:
                        q.append((new_word, steps+1))
                        sett.remove(new_word)
        return 0
 