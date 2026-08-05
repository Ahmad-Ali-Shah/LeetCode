/*
Its O(n^2) which can't run for long results and result Time limit excedded
class Solution {
public:
int maxArea(vector<int>& height) {

    int Area = 0;

    for(int i = 0; i < height.size(); i++){
        for(int j = i; j < height.size(); j++){

            Area = max(Area, (j - i) * min(height[i], height[j]));//min as lesser y is concidered

        }
    }

    return Area;
}

};

*/

//therefore i apply some shought of binary search

class Solution{

public:

int maxArea(vector<int>& height){

    int left = 0;

    int right = height.size()-1;

    int Area = 0;

    while(left < right){ //its O(n)

        Area = max(Area , (right-left) * min(height[left] , height[right]));

        if(height[left] > height[right]){
            // move right
            right--;
        }
        else{
            left++;
        }
    }

    return Area;
}

};