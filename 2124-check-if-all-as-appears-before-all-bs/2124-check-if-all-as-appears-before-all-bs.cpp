class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i < s.size() && s[i] == 'a') i++;
        while(j >= 0 && s[j]== 'b' )j--;


        // while(i<j){
        //     if(s[i] != 'a' && s[j]!= 'b'){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }    

        return i > j;
    }
};