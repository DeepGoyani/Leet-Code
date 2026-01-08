class Solution {
public:

    bool canShip(vector<int>& weights, int days, int cap){
        int total = 0;
        int d = 1;

        for(int w : weights){
            if(total + w > cap){
                d++;
                total = 0;
            }
            total += w;

            if(d > days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;

        for(int w : weights){
            left = max(left, w);
            right += w;
        }

        int ans = right;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(canShip(weights, days, mid)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
