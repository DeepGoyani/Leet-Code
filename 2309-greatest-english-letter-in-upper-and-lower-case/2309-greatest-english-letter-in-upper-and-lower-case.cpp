class Solution {
public:
    string greatestLetter(string s) {
        int n, m, max = 0;
        char ch;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            n = s[i];
            if(n >= 97 && n <= 122){
                for(int j = 0; j < s.size(); j++){
                    m = s[j];
                    if(m == n - 32){
                        if(m > max){
                            max = m;
                            ch = s[j];
                        }
                    }
                }
            }
        }
        if(max != 0){
            ans += ch;
            return ans;
        }
        return "";
    }
};