class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        unordered_map<int, int> suffix;
        for (int x : nums) suffix[x]++;

        unordered_set<int> prefix;

        for (int i = 0; i < n; i++) {
            // add to prefix
            prefix.insert(nums[i]);

            // remove from suffix
            suffix[nums[i]]--;
            if (suffix[nums[i]] == 0) {
                suffix.erase(nums[i]);
            }

            ans[i] = prefix.size() - suffix.size();
        }

        return ans;
    }
};
