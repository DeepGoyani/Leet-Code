class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, n);  // initialize with large value
        
        int last = -n;

        // Left to Right
        for (int i = 0; i < n; i++) {
            if (s[i] == c) last = i;
            ans[i] = i - last;
        }

        // Right to Left
        last = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) last = i;
            ans[i] = min(ans[i], last - i);
        }

        return ans;
    }
};
