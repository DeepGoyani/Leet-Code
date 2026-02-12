class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);
        
        // Count digit frequencies
        while (n > 0) {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }
        
        int minFreq = INT_MAX;
        int result = 0;
        
        // Find the least frequent digit (smallest digit if tie)
        for (int i = 0; i <= 9; i++) {
            if (freq[i] > 0 && freq[i] < minFreq) {
                minFreq = freq[i];
                result = i;
            }
        }
        
        return result;
    }
};
