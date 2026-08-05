class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnIndex ;
        for(int i=0 ; i<nums.size()-1 ; i++){
           // if(nums[i] + nums[i+1] == target){
             //   returnIndex.push_back(i);
               // returnIndex.push_back(i+1);
                //i++;
            //}
            for(int j= i+1 ; j<nums.size() ; j++){
                if(nums[i] + nums[j] == target){
                    returnIndex.push_back(i);
                    returnIndex.push_back(j);
                    return returnIndex;
                }
            }


        }
        return  returnIndex;
        
    }
};