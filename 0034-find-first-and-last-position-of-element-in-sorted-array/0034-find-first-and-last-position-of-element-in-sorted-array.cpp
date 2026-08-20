class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // sorted + search = binary search

        vector<int> result;

        int low = 0;
        int high = nums.size() - 1;

        if (nums.empty()) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int first = -1;
        int last = -1;

        // find first occurrence
        while (low <= high) {

            int mid = floor((low + high) / 2);

            if (nums[mid] == target) {
                first = mid;

                // search to the left
                high = mid - 1;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                // to the left
                high = mid - 1;
            }
        }

        // if not found
        if (first == -1) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        low = first;
        high = nums.size() - 1;

        // find last occurrence
        while (low <= high) {

            int mid = floor((low + high) / 2);

            if (nums[mid] == target) {
                last = mid;

                // search to the right
                low = mid + 1;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                // to the left
                high = mid - 1;
            }
        }

        result.push_back(first);
        result.push_back(last);

        return result;
    }
};