class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string Commonprefix = "";

         string baseString = strs[0];
         
         int counter =0;

         while(baseString[counter] !='\0'){

            for(int i=0 ; i<strs.size() ; i++){
                if(strs[i][counter] != baseString[counter]){
                    return Commonprefix ;
                }
            }

            Commonprefix.push_back(baseString[counter]);
            counter++;
         }
       return Commonprefix;
    }
};