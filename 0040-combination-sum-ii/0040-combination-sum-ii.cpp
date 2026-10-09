class Solution {
    vector<int> UniqueCombinations;
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target, int index = 0, int sum = 0) {

        // Base case
        if (sum == target) {

            result.push_back(UniqueCombinations);

            return result;

        }

        if (sum > target || index >= candidates.size()) {

            return result;
        }

        // Sort to handle duplicate combinations
        sort(candidates.begin(), candidates.end());

        
        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (sum + candidates[i] > target) {
                break;
            }

            
            UniqueCombinations.push_back(candidates[i]);

            
            combinationSum2(candidates, target, i + 1, sum + candidates[i]);

            // Backtrack
            UniqueCombinations.pop_back();
        }

        return result;
    }
};