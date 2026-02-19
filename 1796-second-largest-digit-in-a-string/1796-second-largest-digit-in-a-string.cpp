class Solution {
public:
    int secondHighest(string s) {
        int max = -1, secondMax = -1, val = 0;
        for (char x : s) {
            if (isdigit(x)) {
                val = int(x) - 48;
                if (val > max) {
                    secondMax = max;
                    max = val;
                } else if (val > secondMax && val < max)
                    secondMax = val;
            }
        }
        return secondMax;
    }
};