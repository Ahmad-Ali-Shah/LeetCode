class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        for(int i = 0; i < nums.size() - 1; i++){

            if(nums[i] == nums[i + 1]){
                continue;
            }

            bool isMonotonicsIncreasing = (nums[i] < nums[i + 1]);

            for(int j = i + 1; j < nums.size(); j++){

                if(isMonotonicsIncreasing){

                    if(nums[j - 1] > nums[j]){
                        return false;
                    }

                }
                else{

                    if(nums[j - 1] < nums[j]){
                        return false;
                    }
                }
            }

            return true;
        }

        return true;
    }
};