class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        sort(A.begin(), A.end());
        vector<vector<string>> res;
        
        string prefix = "";
        
        for (char c : searchWord) {
            prefix += c;
            vector<string> temp;
            
            auto it = lower_bound(A.begin(), A.end(), prefix);
            
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string &word = *(it + i);
                
                if (word.compare(0, prefix.size(), prefix) != 0)
                    break;
                    
                temp.push_back(word);
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};