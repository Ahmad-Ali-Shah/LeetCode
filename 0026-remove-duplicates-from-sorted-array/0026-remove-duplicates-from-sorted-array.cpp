class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int sizeOf = nums.size();

        for(int i = 0; i < sizeOf; i++){
            for(int j = i + 1; j < sizeOf; j++){
                if(nums[i] == nums[j]){

                    for(int k = j; k < sizeOf - 1; k++){
                        swap(nums[k], nums[k + 1]);
                    }

                    sizeOf--;
                    j--; //so it starts comparing from same 
                }
            }
        }

        return sizeOf;
    }
};