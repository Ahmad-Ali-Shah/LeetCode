
class Solution {
    vector<int> permutaSON;
    vector<vector<int>> results;
    vector<bool> used;

    vector<vector<int>> backtrack(vector<int>& nums, int layer, int trav) {

        // base case
        if(layer == nums.size()) {
            results.push_back(permutaSON);
            return results;
        }

        // no more choices at this layer
        if(trav == nums.size()) {
            return results;
        }

        // choose the current element if not already used
        if(!used[trav]) {
            permutaSON.push_back(nums[trav]);
            used[trav] = true;

            // move deeper
            backtrack(nums, layer + 1, 0);

            // backtrack: pop and mark unused
            permutaSON.pop_back();
            used[trav] = false;
        }

        // move to the next choice
        backtrack(nums, layer, trav + 1);

        return results;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        permutaSON.clear();
        results.clear();
        used.assign(nums.size(), false);

        backtrack(nums, 0, 0);

        return results;
    }
};
