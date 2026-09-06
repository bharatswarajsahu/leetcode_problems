class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;
        int left = 0;

        for (int num : nums) {
            total += num;
        }

        vector<int> answer(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int right = total - left - nums[i];

            answer[i] = abs(left - right);

            left += nums[i];
        }

        return answer;
    }
};