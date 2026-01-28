class Solution {
private:
    vector<int> original;
    vector<int> curr;

public:
    Solution(vector<int>& nums) {
        original = nums;
        curr = nums;
    }
    
    vector<int> reset() {
        curr = original;
        return curr;
    }
    
    vector<int> shuffle() {
        for (int i = curr.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(curr[i], curr[j]);
        }
        return curr;
    }
};
