class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int ones = 0;
        for (int n : nums) {
            ones += (n & 1);
        }
        vector<int> result(nums.size(), 0);
        for (int i = (int)nums.size() - ones; i < (int)nums.size(); i++) {
            result[i] = 1;
        }
        return result;        
    }
};