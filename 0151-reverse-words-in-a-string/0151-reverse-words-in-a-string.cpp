class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        
        // Step 1: Collect words manually (ignore extra spaces)
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }

        // add last word if exists
        if (!temp.empty()) words.push_back(temp);

        // Step 2: Reverse the list of words
        reverse(words.begin(), words.end());

        // Step 3: Join the words
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }

        return result;
    }
};
