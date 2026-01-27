class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int freq[1001] = {0};

        // Count frequency of each cost
        for (int i = 0; i < cost.size(); i++) {
            freq[cost[i]]++;
        }

        int total = 0;
        int count = 0; // counts candies in group of 3

        // Traverse from highest cost to lowest
        for (int price = 1000; price >= 1; price--) {
            while (freq[price] > 0) {
                count++;

                // Pay for first 2 candies
                if (count % 3 != 0) {
                    total += price;
                }
                // 3rd candy is free (do nothing)

                freq[price]--;
            }
        }

        return total;
    }
};
