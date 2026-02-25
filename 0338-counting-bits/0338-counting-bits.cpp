class Solution {
public:
    vector<int> countBits(int n) {
        if(!n){
            return {0};
        }
        if(n==1){
            return{0,1};
        }
        vector<int> ans = {0,1};
        for(int i=2; i<=n; i++){
            if(i%2){
                ans.push_back(ans[i-1]+1);
            }
            else {
                ans.push_back(ans[i/2]);
            }
        }
        return ans;
    }
};