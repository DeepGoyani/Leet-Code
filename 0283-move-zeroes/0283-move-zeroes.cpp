class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int length=nums.size();
      int j=0;
      for (int i=0;i<length;i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
      }
        while(j<nums.size()){
            nums[j]=0;
            j++;
        }
      
    }
};