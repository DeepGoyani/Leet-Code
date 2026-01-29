class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;

        int f1[26] = {0};
        int f2[26] = {0};

        for (char c : word1)
            f1[c - 'a']++;

        for (char c : word2)
            f2[c - 'a']++;

        // Condition 1: same characters present
        for (int i = 0; i < 26; i++) {
            if ((f1[i] == 0 && f2[i] != 0) || (f1[i] != 0 && f2[i] == 0))
                return false;
        }

        // Condition 2: match frequency counts manually
        bool used[26] = {false};

        for (int i = 0; i < 26; i++) {
            if (f1[i] == 0) continue;

            bool found = false;
            for (int j = 0; j < 26; j++) {
                if (!used[j] && f1[i] == f2[j]) {
                    used[j] = true;
                    found = true;
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }
};
