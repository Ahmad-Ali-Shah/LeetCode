class Solution {
    vector<int> storedValues;
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int index = 0, int sum = 0) {

        // Base case if sum reaches target
        if (sum == target) {

            result.push_back(storedValues);

            return result;
        }

        else if (sum > target || index >= candidates.size()) {

            return result; // same result vector 
        }

        // Add the current value

        sum += candidates[index];

        storedValues.push_back(candidates[index]);


        // Choose the same value again point in backtracking if you are going to store same value then ask iiteractiion wse 
        combinationSum(candidates, target, index, sum);

        // Backtrack decrement all operation you have done above 
        storedValues.pop_back();
        sum -= candidates[index];

      
        combinationSum(candidates, target, index + 1, sum);

        return result;
    }
};