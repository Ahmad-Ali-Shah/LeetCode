class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // sort it 

        sort(nums.begin() , nums.end());
        

        int highest = 0;

        for(int i= 0 ; i< nums.size() ; i+=2){
          highest+=nums[i];
        }
        return highest;
    }
};