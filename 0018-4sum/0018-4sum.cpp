class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());//sorting for the binary search to apply 

    for(int i = 0 ; i < nums.size() ; i++){

        if(i > 0 && nums[i] == nums[i-1]){
            continue; //remove the hell same terms 
        }

        for(int j = i + 1 ; j < nums.size() ; j++){

            if(j > i + 1 && nums[j] == nums[j-1]){
                continue; //same remove same repeted terms ITS VVV IMPORTANT IF YOU DIDNOT YOU NEED TO DO IT AGAIN OUTSIDE BY MAKING IT AS O(N^4) PROBLEM IG
            }

            int low = j + 1;

            int height = nums.size() - 1;

            while(low < height){

                long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[low] + nums[height]; //converting sum of long long may be sum of that increase the int limit causing overflow 

                if(sum > target){
                    height--;
                }

                else if(sum < target){
                    low++;
                }

                else{

                    vector<int> temp {nums[i], nums[j], nums[low], nums[height]};

                    result.push_back(temp);

                    low++;
                    height--;

                    while(low < height && nums[low] == nums[low-1]){
                        low++; //again remove duplicates after next 
                    }

                    while(low < height && nums[height] == nums[height+1]){
                        height--;
                    }

                }

            }
        }
    }

    return result;
}
};