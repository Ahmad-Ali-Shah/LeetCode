

/////////////////////////////

// max i shall take is O(n^2)

////////////////////////////

class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {

    int sum = 0;
    unsigned int diff = INT_MAX;

    for(int i = 0; i < nums.size(); i++){

        for(int j = i + 1; j < nums.size(); j++){

            for(int k = j + 1; k < nums.size(); k++){

                int current = nums[i] + nums[j] + nums[k];

                if(abs(current - target) < diff){
                    diff = abs(current - target);
                    sum = current;
                }

            }
        }
    }

    return sum;
}
};