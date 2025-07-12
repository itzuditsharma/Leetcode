class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans;

        for(int i = 0;i < s.length(); i++){
            char ch = s[i];

            if(ch != ' '){
                temp += ch;
            }else{
                if(ans != ""){
                    ans = temp + (temp == ""?"": " ") + ans;
                }else{
                    ans = temp;
                }
                temp = "";
            }
        }

        if(temp != ""){
            if(ans != "") ans = temp + " " + ans;
            else{
                ans = temp;
            }
        }
        return ans;
    }
};