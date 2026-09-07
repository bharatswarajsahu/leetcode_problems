
        
    class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int currentDays = 1;
        int currentWeight = 0;
        for (int w : weights) {
            if (currentWeight + w > capacity) {
                currentDays++;
                currentWeight = 0;
            }
            currentWeight += w;
        }
        return currentDays <= days;
    }
};