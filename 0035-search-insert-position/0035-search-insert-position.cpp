class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // again sort + target = binary search

        int low = 0;
        int high = nums.size() - 1;
        int mid = floor((low + high) / 2);

        while (low <= high) {

            mid = floor((low + high) / 2);

            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] > target) {
                high = mid - 1;
                
            } else {
                low = mid + 1;
            }
        }

        // low is the correct insert position
        return low;
    }
};