class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count = 0;
        string s, temp;
        bool check = false;
        for(int i = 0; i < words.size(); i++){
            temp = words[i];
            s = chars;
            for(int j = 0; j < temp.size(); j++){
                check = false;
                for(int k = 0; k < s.size(); k++){
                    if(temp[j] == s[k]){
                        s[k] = '0';
                        check = true;
                        break;
                    }
                }
                if(check == false) break;
            }
            if(check == true){
                count += temp.size();
            }
        }
        return count;
    }
};