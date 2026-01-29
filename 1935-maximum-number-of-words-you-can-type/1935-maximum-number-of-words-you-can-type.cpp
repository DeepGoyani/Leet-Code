class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {false};

        // mark broken letters
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        int count = 0;
        bool canType = true;

        for (int i = 0; i <= text.length(); i++) {
            if (i == text.length() || text[i] == ' ') {
                if (canType)
                    count++;
                canType = true;   // reset for next word
            } else {
                if (broken[text[i] - 'a']) {
                    canType = false;
                }
            }
        }

        return count;
    }
};
