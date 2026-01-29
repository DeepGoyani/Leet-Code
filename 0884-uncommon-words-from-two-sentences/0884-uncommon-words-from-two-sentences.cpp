class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        vector<string> ans;
        string word = "";

        // process first sentence
        for (int i = 0; i <= s1.size(); i++) {
            if (i == s1.size() || s1[i] == ' ') {
                freq[word]++;
                word = "";
            } else {
                word += s1[i];
            }
        }

        // process second sentence
        for (int i = 0; i <= s2.size(); i++) {
            if (i == s2.size() || s2[i] == ' ') {
                freq[word]++;
                word = "";
            } else {
                word += s2[i];
            }
        }

        // collect uncommon words
        for (auto it : freq) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
