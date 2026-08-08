class Solution {
public:
int removeDuplicates(vector<int>& nums) {
/*
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


 its o(n^2) which is too slow so i need to fix it 
*/
int found = 0;

for(int num = 1; num < nums.size(); num++){
    if(nums[num] != nums[found]){
        found++;
        nums[found] = nums[num]; //move it forward and forward
    }
}

return found + 1;
}

};