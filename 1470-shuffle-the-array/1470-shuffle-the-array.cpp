class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        ans.reserve(2 * n);   // optional optimization

        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);      // x1, x2, ...
            ans.push_back(nums[i + n]);  // y1, y2, ...
        }
        return ans;
    }
};
