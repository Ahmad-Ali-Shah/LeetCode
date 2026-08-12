class Solution {
public:
    int strStr(string haystack, string needle) {

        int index = 0;
        int strLength = needle.length();
        bool isFound = false;

        if(strLength > haystack.length()){
            return -1;
        }

        while(haystack[index] != 0)
        {
            string temp = "";

            for(int i = index; i < haystack.size() && temp.size() < needle.size(); i++){
               
               temp += haystack[i];

            }

            if(temp.compare(needle) == 0){
                isFound = true;
                break;
            }
            
            index++;
        }

        if(!isFound){
            return -1;
        }
        else{
            return index;
        }
    }
};