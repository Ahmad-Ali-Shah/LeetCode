/*
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        int highest = 0;

        for(int i = 0; i < nums.size(); i++){

            int k = i;
            int m = k;
            int counter = 0;

            do{
                m = nums[m];
                counter++;
            }while(k != m);

            if(counter > highest){
                highest = counter;
            }
        }

        return highest;
    }
};
more time takiing method 


*/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        int highest = 0;
        vector<bool> visited(nums.size(), false);

        for(int i = 0; i < nums.size(); i++){

            if(visited[i]){
                continue; // added just a little optimization if visited dont visit again 
            }

            int k = i;
            int m = k;
            int counter = 0;

            do{
                visited[m] = true;
                m = nums[m];
                counter++;
            }while(k != m);

            if(counter > highest){
                highest = counter;
            }
        }

        return highest;
    }
};