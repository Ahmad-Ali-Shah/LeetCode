
class Solution {
public:
    int maxSubArray(vector<int>& nums, int index = -1, int sum = 0) {

        if(index == -1) {
            index = nums.size() - 1;
            sum = nums[index];
        }

        if(index == 0) {
            return sum;
        }

        int current = max(nums[index - 1], nums[index - 1] + sum);

        int best = maxSubArray(nums, index - 1, current);

        return max(sum, best);
    }
};
