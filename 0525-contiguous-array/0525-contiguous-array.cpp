/*

class Solution {

    int getSize(vector<int> nums){
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                sum -= 1;
            }
            else{
                sum += 1;
            }
        }

        if(sum == 0){
            return nums.size();
        }
        else{
            return -1;
        }
    }

public:
    int findMaxLength(vector<int>& nums) {

        int highest = 0;

        for(int i = 0; i < nums.size(); i++){

            vector<int> temp;

            for(int j = i; j < nums.size(); j++){

                temp.push_back(nums[j]);

                int x = getSize(temp);

                if(x > highest)
                    highest = x;
            }
        }

        return highest;
    }
};

*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> firstIndex(2 * n + 1, -2);
        firstIndex[n] = -1;

        int sum = 0;
        int highest = 0;

        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            int idx = sum + n;

            if (firstIndex[idx] != -2) {
                highest = max(highest, i - firstIndex[idx]);
            } else {
                firstIndex[idx] = i;
            }
        }

        return highest;
    }
};