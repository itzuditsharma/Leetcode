class Solution {
public:

    long long helper(string s, int i, long long result){
        if(i >= s.length() || !isdigit(s[i])){
            return result;
        }

        int digit = s[i] - '0';
        result = result * 10 + digit;
        if(result > INT_MAX) return result;
        return helper(s, i+1, result);

    }

    int myAtoi(string s) {
        int i = 0;
        bool flag = false;
        if(s.empty()) return 0;
        while(i < s.length() && s[i] == ' ') i++;

        s = s.substr(i);

        i =  0;
        if(s[i] == '-'){
            flag = true;
            i++;
        }else if(s[i] == '+'){
            i++;
        }

        long long res = helper(s, i, 0);
        if(flag == true){
            if(-res < INT_MIN) return INT_MIN;
            else return -res;
        }else{
            if(res > INT_MAX) return INT_MAX;
            else return res;
        }
    }
};