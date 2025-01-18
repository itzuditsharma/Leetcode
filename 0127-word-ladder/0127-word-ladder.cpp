class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>sett(wordList.begin(), wordList.end());
        queue<pair<string, int>> q; //word, steps
        q.push({beginWord, 1});
        sett.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c <='z'; c++){
                    word[i] = c;

                    if(sett.find(word) != sett.end()){
                        q.push({word, steps + 1});
                        sett.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};