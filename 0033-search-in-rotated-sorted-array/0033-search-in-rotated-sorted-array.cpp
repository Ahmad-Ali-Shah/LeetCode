class Solution {
public:
    int search(vector<int>& nums, int target) {
        // when it says sorted and search apply binary search
        // also between two non sorted there is one sorted

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = floor((low + high) / 2);

            
            if (nums[mid] == target) {
                return mid;
            }

            // left side is sorted
            if (nums[low] <= nums[mid]) {

                // target is inside the sorted left side
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // right side is sorted
            else {

                // target is inside the sorted right side
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};