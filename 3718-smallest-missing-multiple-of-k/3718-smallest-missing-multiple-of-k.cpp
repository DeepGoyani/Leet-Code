class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int search = k;
        for (const int& num : nums) {
            if (num == search)
                search += k;
            else if (num > search)
                return search;
        }

        return search;
    }
};