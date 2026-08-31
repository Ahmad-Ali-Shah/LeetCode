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
      
        // its btw a pattern ie in ordert to minimize the flow what should you do is take the modulus of that like k%10 so it be easy to solve

        // make it like o(n)


        reverse(nums.begin(), nums.end()); //first reverse the whole array its like logo block

        // reverse the other

        reverse(nums.begin(), nums.begin()+k); // here we divide it in two half so its a problem by division into cases

        //now for the last ones

        reverse(nums.begin()+k, nums.end());

    }
};
//that's is a more optimized way 