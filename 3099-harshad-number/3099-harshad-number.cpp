class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int temp = x;

        // calculate sum of digits
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        // check Harshad condition
        if (x % sum == 0)
            return sum;
        else
            return -1;
    }
};
