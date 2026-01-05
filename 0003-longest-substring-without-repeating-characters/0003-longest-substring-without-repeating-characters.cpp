class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> freq(256, -1);   // stores last index of each character
        int left = 0;                // start of window
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If character already seen inside current window
            if(freq[c] != -1 && freq[c] >= left) {
                left = freq[c] + 1;  // move left pointer
            }

            freq[c] = right;         // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
