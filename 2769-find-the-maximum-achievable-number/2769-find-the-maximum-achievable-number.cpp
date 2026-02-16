class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int a=num, b=num, c=num, d=num;
        a += t; a += t;      // num + 2t
        b += t; b -= t;      // num
        c -= t; c += t;      // num
        d -= t; d -= t;      // num - 2t
        return max({a, b, c, d});
    }
};