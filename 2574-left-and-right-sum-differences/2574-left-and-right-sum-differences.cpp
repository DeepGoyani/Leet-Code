class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int lsum = 0, rsum = 0, sz = nums.size(), j = 0, k = 0;
        vector<int> ans{};
        for(int i = 0; i < sz; ++i)
        {
            j = i+1;
            k = i-1;
            lsum = 0;
            rsum = 0;
            while(j < sz)
                rsum += nums[j++];
            
            while(k >= 0)
                lsum += nums[k--];
            
            ans.push_back(abs(lsum-rsum));
        }
        return ans;
    }
};