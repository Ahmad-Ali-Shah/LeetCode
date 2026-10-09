
class Solution {
    vector<int> stored;
    vector<vector<int>> valueNeeded;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums, int level = 0) {

        // base case
        if(level == nums.size()) {
            valueNeeded.push_back(nums);
            return valueNeeded;
        }

        for(int i = level; i < nums.size(); i++) {

            // skip duplicate choices at this level
            bool repeated = false;

            for(int j = level; j < i; j++) {
                if(nums[j] == nums[i]) {
                    repeated = true;
                    break;
                }
            }

            if(repeated) {
                continue;
            }

            // swap
            swap(nums[level], nums[i]);

            // recursive call
            permuteUnique(nums, level + 1);

            // backtrack: swap again
            swap(nums[level], nums[i]);
        }

        return valueNeeded;
    }
};
