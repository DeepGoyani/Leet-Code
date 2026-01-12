class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Step 1: Check if both strings can form each other
        if (str1 + str2 != str2 + str1)
            return "";

        // Step 2: compute gcd of lengths manually
        int g = manualGCD(str1.length(), str2.length());

        // Step 3: return prefix
        return str1.substr(0, g);
    }

    // Manual GCD (no built-in)
    int manualGCD(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
};
