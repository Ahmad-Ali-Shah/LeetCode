class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }

        bool isIncrease = true;
        bool increased = false; // tracks whether we actually increased

        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] < arr[i + 1]){
                increased = true;
            }

            if(arr[i] > arr[i + 1]){
                isIncrease = false;
            }

            if(arr[i] == arr[i + 1]){
                return false;
            }

            if(!isIncrease && arr[i] <= arr[i + 1]){
                return false;// not increase multipl tiime 
            }
        }

        if(isIncrease || !increased){
            return false; // only increasing or decreasng 
        }

        return true;
    }
};