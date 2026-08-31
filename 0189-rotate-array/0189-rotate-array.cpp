/*
class Solution {
    void traverseOne(vector<int>& nums){

        // take last

        int last = nums[nums.size()-1];
        int tempTostore = nums[0];

        for(int i = 0; i < nums.size(); i++){

            if(i == 0){

                nums[i] = last;

                if(i + 1 < nums.size()){
                    int temp = tempTostore;
                    tempTostore = nums[i+1];
                    nums[i+1] = temp;
                    i++;
                }

            }

            else if(i < nums.size()-1){

                int temp = tempTostore;
                tempTostore = nums[i];
                nums[i] = temp;

            }

            else{

                // last element just fill it

                nums[i] = tempTostore;
            }
        }
    }

public:
    void rotate(vector<int>& nums, int k) {

        if(nums.size() == 0 || nums.size() == 1)
            return;

        k = k % nums.size();

        for(int i = 0; i < k; i++){
            traverseOne(nums); // traveerse one each time
        }
    }
};

take o(n *k) time vvvv aslow 
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if(nums.size() <= 1)
            return;

        k = k % nums.size();

        vector<int> temp;

        for(int i = nums.size() - k; i < nums.size(); i++){
            temp.push_back(nums[i]); // move oppositly 
        }

        for(int i = nums.size() - 1; i >= k; i--){
            nums[i] = nums[i-k];
        }

        for(int i = 0; i < k; i++){
            nums[i] = temp[i];
        }
    }
};
//that's is a more optimized way 