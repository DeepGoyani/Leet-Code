class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n=bulbs.size();
        vector<int> ans;
        vector<int> freq(101,0);
        for(int i=0;i<n;i++){
            freq[bulbs[i]]++;
        }
        for(int i=1;i<=100;i++){
            if(freq[i]%2!=0) ans.push_back(i);
        }
        return ans;
    }
};