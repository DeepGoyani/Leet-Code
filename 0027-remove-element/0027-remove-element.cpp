class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int place =0;
      for (int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[place]=nums[i];
            place++;
        }
      }
      return place;
    }
};
