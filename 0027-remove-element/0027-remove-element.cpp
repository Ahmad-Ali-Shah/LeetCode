class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int lessen = 0;
        int end = nums.size() - 1;

        for(int i = 0; i <= end; i++){

            if(nums[i] == val){

                while(end >= i && nums[end] == val){
                    end--;
                    lessen++;
                }

                if(end >= i){
                    swap(nums[i], nums[end]);
                    end--;
                    lessen++;
                    i--;
                }
            }
        }

        return nums.size() - lessen;
    }
};