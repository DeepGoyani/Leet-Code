class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1,
                              vector<int>& nums2,
                              vector<int>& nums3) {

        int cnt[101] = {0};

        for (int x : nums1) {
            cnt[x] |= 1;
        }

        for (int x : nums2) {
            cnt[x] |= 2;
        }

        for (int x : nums3) {
            cnt[x] |= 4;
        }

        vector<int> ans;

        for (int i = 1; i <= 100; i++) {
            int mask = cnt[i];
            if ((mask & (mask - 1)) != 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
