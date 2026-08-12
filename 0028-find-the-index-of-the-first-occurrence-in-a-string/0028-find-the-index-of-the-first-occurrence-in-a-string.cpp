/*
lesser optimized code
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


*/



class Solution {
public:
    int strStr(string haystack, string needle) {

        int index = 0;
        int strLength = needle.length(); //.length for getting length of string
        bool isFound = false;

        if(strLength > haystack.length()){
            return -1;
        }

        while(index <=( haystack.length() - needle.length()))
        {
            int i = 0;

            for(i = 0; i < needle.length(); i++){
                if(haystack[index + i] != needle[i]){
                    break;
                }
            }

            if(i == needle.length()){
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