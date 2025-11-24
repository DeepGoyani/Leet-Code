class Solution {
public:
    string longestPalindrome(string s) {
         if (s.empty()) {
        return "";
    }

    // If the input string has only one character, that character itself is the longest palindrome.
    if (s.length() == 1) {
        return s;
    }

    // Initialize variables to keep track of the start index and maximum length of the longest palindrome found so far.
    int start = 0; // 'start' will store the starting index of the longest palindrome.
    int maxLength = 1; // 'maxLength' will store the length of the longest palindrome. It's initialized to 1 because a single character is always a palindrome.

    // Loop through each character of the string. Each character can be a potential center of a palindrome.
    // 'i' represents the current center of expansion.
    for (int i = 0; i < s.length(); ++i) {
        // Expand around 'i' as a single center (odd length palindromes, e.g., "aba").
        // 'left' and 'right' pointers are initialized to 'i'.
        int left = i, right = i;
        // While the pointers are within bounds and the characters match, expand outwards.
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            // Calculate the current length of this palindrome.
            int currentLength = right - left + 1;
            // If the current palindrome is longer than the 'maxLength' found so far, update 'maxLength' and 'start'.
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left; // Update the start index to the current 'left' pointer.
            }
            // Move pointers inward to expand.
            left--;
            right++;
        }

        // Expand around 'i' and 'i+1' as a double center (even length palindromes, e.g., "abba").
        // 'left' is initialized to 'i', 'right' is initialized to 'i+1'.
        left = i;
        right = i + 1;
        // While the pointers are within bounds and the characters match, expand outwards.
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            // Calculate the current length.
            int currentLength = right - left + 1;
            // If the current palindrome is longer, update 'maxLength' and 'start'.
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left; // Update the start index to the current 'left' pointer.
            }
            // Move pointers inward to expand.
            left--;
            right++;
        }
    }

    // After checking all possible centers, return the substring from 'start' with 'maxLength'.
    // The substr method extracts a portion of the string.
    return s.substr(start, maxLength);
}
    
};