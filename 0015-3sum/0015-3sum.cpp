/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int found = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {

                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp{nums[i], nums[j], nums[k]};

                        sort(temp.begin(), temp.end());

                        bool isThere = false;

                        for (int i = 0; i < result.size(); i++) {
                            if (temp == result[i]) {
                                isThere = true;
                                break;
                            }
                        }
                        if (!isThere) {
                            result.push_back(temp);
                        }
                    }
                }
            }
        }

        return result;
    }
};
O(n^3) dont know but it takes a lot of time so better not to do 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {

        vector<vector<int>> result;

        //soriting it
        sort(num.begin(), num.end());


        //applying two pointer in terms of loop

        for(int i = 0; i < num.size(); i++) {


            // skip duplicate i
            if(i > 0 && num[i] == num[i-1])
                continue;


            //now here we have 3 pointers one to 0 one to 1 and one to last
            int low = i + 1;
            int height = num.size() - 1;


            while(low < height) {


                if(num[i] + num[low] + num[height] < 0) {
                    low++;
                }


                else if(num[i] + num[low] + num[height] > 0) {
                    height--;
                }


                else {

                    //equals to 0
                    vector<int> temp{num[i], num[low], num[height]};
                    result.push_back(temp);


                    low++;
                    height--;


                    // remove duplicate low
                    while(low < height && num[low] == num[low-1])
                        low++;


                    // remove duplicate height
                    while(low < height && num[height] == num[height+1])
                        height--;
                }
            }
        }


        return result;
    }
};