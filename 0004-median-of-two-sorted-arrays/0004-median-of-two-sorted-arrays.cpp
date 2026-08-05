class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int sum = nums1.size() + nums2.size();

    vector<int> result;

    
    for(int i = 0; i < nums1.size(); i++){
        result.push_back(nums1[i]);
    }

    for(int i = 0; i < nums2.size(); i++){
        result.push_back(nums2[i]);
    }

    
    sort(result.begin(), result.end());


    
    if(sum % 2 != 0){
        return result[sum/2];
    }

   
    else{
        return (result[sum/2 - 1] + result[sum/2]) / 2.0;
    }
}
};