/*

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


It o(n^3) which takes 835 ms to run along with takes 14.14 mb which is a lot 
so i need to do it with double pointer 

*/


/////////////////////////////

// max i shall take is O(n^2)

////////////////////////////

class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {

    int sum = 0;
    int diff;
    int maxDiff = INT_MAX;


    sort(nums.begin(), nums.end());// as two pointer aka binary search work for only sorted array 


    for(int i = 0 ; i < nums.size() ; i++){


        int j = i + 1;
        int k = nums.size() - 1;


        while(j < k){  //it might cross over k also both need identical therefore j<k if not unique then we can do might j==k dw 


            int current = nums[i] + nums[j] + nums[k];

            
            diff = current - target;


            if(diff > 0){
                k--;
            }
            else if(diff < 0){
                j++;
            }
            else{
                return current;
            }


            if(abs(diff) < maxDiff){
                maxDiff = abs(diff);
                sum = current;
            }



        }
    }


    return sum;
}

};