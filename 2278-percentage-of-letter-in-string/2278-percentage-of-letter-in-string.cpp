class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        
        // Count occurrences of the given letter
        for (char ch : s) {
            if (ch == letter) {
                count++;
            }
        }
        
        // Calculate percentage
        int percentage = (count * 100) / s.length();
        
        return percentage;
    }
};
