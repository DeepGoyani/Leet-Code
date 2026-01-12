class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            // Check if current, left, and right are empty
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                
                flowerbed[i] = 1; // plant flower
                n--;              // one less flower needed

                if (n == 0) return true; // already placed all
            }
        }

        return n <= 0;
    }
};
