class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> sett(wordList.begin(), wordList.end());
        sett.erase(beginWord);   //Erasing is our way of marking visited

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    if(sett.find(word)!=sett.end()){
                        sett.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
            if(word == endWord) return steps;

        }
        return 0;
    }
};