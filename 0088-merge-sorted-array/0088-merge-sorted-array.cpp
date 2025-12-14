class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m;
        for (int i = 0; i < n; i++) {
            nums1[j] = nums2[i];
            j++;
        }
        for (int i = 0; i < m + n; i++) {
        for (int k = i + 1; k < m + n; k++) {
             if (nums1[i] > nums1[k]) {
                swap(nums1[i], nums1[k]);
                }
            }
        }
        
    }
};