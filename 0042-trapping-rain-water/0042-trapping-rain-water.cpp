class Solution {
public:
    int trap(vector<int>& height) {

        int sum = 0;

        int max = height[0];

        for(int i = 0; i < height.size(); i++){

            if(max < height[i]){
                max = height[i];
            }

            // now for sum

            int rightMax = height[i];

            for(int j = i + 1; j < height.size(); j++){
                if(rightMax < height[j]){
                    rightMax = height[j];
                }
            }

            int water = min(max, rightMax) - height[i];

            if(water > 0){
                sum += water;
            }
        }

        return sum;
    }
};