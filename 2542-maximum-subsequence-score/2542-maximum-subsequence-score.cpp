class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i<nums1.size(); i++) v.push_back({nums2[i], nums1[i]});
        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long sum=0, ans=0;
        for(auto &[nums2, nums1] : v){
            sum += nums1;
            pq.push(nums1);
            if(pq.size()==k){
                ans = max(ans, sum * (long long)nums2);
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};