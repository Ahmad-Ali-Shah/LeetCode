class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // Sort the array
        sort(nums.begin(), nums.end());

        int minValue = 1;

        for (int i = 0; i < nums.size(); i++) {

            // Ignore negative numbers and zero
            if (nums[i] <= 0) {
                continue;
            }

            // Ignore duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] == minValue) {
                minValue++;
            }
            else if (nums[i] > minValue) {
                
                return minValue;
            }
        }

        return minValue;
    }
};