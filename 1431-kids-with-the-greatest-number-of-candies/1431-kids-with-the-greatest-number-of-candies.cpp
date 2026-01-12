class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = candies[0];
        for (int i = 1; i < candies.size(); ++i) {
            if (candies[i] > greatest) {
                greatest = candies[i];
            }
        }
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= greatest) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }

        return result;
    }
};
