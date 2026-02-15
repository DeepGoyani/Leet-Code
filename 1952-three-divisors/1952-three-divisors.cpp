class Solution {
public:
    bool isThree(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {if (n % i == 0) {ans++;}}
        if (ans == 3) {return true;}
        return false;
    }
};