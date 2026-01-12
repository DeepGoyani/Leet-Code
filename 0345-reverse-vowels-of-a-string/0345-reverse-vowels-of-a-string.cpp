class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;

            // swap vowels
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }

        return s;
    }

    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
};
