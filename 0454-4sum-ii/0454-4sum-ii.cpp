class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        int count = 0;

        // Store sums of nums1 and nums2
        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }

        // Check sums of nums3 and nums4
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
                if (mp.count(target)) {
                    count += mp[target];
                }
            }
        }

        return count;
    }
};
