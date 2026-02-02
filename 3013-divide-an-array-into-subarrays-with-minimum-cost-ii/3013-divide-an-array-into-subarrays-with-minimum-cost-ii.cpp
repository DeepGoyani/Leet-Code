class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        priority_queue<int> small; // max heap
        priority_queue<int, vector<int>, greater<int>> large; // min heap
        unordered_map<int, int> delayed;

        long long sumSmall = 0;
        int smallSize = 0; // REAL size of valid elements in small

        auto cleanSmall = [&]() {
            while (!small.empty() && delayed[small.top()]) {
                delayed[small.top()]--;
                small.pop();
            }
        };

        auto cleanLarge = [&]() {
            while (!large.empty() && delayed[large.top()]) {
                delayed[large.top()]--;
                large.pop();
            }
        };

        auto balance = [&]() {
            cleanSmall();
            cleanLarge();

            while (smallSize > k - 1) {
                int x = small.top(); small.pop();
                sumSmall -= x;
                smallSize--;
                large.push(x);
                cleanSmall();
            }

            while (smallSize < k - 1) {
                int x = large.top(); large.pop();
                sumSmall += x;
                smallSize++;
                small.push(x);
                cleanLarge();
            }
        };

        // initial window
        for (int i = 1; i <= dist + 1; i++) {
            small.push(nums[i]);
            sumSmall += nums[i];
            smallSize++;
        }

        balance();
        long long ans = nums[0] + sumSmall;

        // sliding window
        for (int i = dist + 2; i < n; i++) {
            int add = nums[i];
            int rem = nums[i - (dist + 1)];

            // mark removal
            delayed[rem]++;
            if (!small.empty() && rem <= small.top()) {
                sumSmall -= rem;
                smallSize--;
            }

            // add new element
            if (!small.empty() && add <= small.top()) {
                small.push(add);
                sumSmall += add;
                smallSize++;
            } else {
                large.push(add);
            }

            balance();
            ans = min(ans, nums[0] + sumSmall);
        }

        return ans;
    }
};
