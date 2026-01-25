class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int first[26];
        
        // initialize with -1
        for(int i = 0; i < 26; i++) {
            first[i] = -1;
        }

        int ans = -1;

        for(int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';

            // if character seen before
            if(first[idx] != -1) {
                ans = max(ans, i - first[idx] - 1);
            } else {
                // store first occurrence
                first[idx] = i;
            }
        }

        return ans;
    }
};
