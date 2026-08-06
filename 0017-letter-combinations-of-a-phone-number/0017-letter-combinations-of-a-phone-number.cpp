//making modular hash function

namespace Myhash{
int hash(int val){
    return val%10;
}
}

char table[8][5] = {
{'a', 'b', 'c', '\0' , '\0'},   // 2
{'d', 'e', 'f', '\0' , '\0'},   // 3
{'g', 'h', 'i', '\0' , '\0'},   // 4
{'j', 'k', 'l', '\0' , '\0'},   // 5
{'m', 'n', 'o', '\0' , '\0'},   // 6
{'p', 'q', 'r', 's'  , '\0'},   // 7
{'t', 'u', 'v', '\0' , '\0'},   // 8
{'w', 'x', 'y', 'z'  , '\0'}    // 9
};

class Solution {
public:
vector<string> letterCombinations(string digits) {

    vector<string> output;

    if(digits.empty())
        return output;

    
    int index = digits[0]-'2'; 

    for(int i=0 ; i<5 && table[index][i]!='\0' ; i++){
        string s;
        s.push_back(table[index][i]);
        output.push_back(s);

    }

    for(int i=1 ; i<digits.size() ; i++){

        index = digits[i]-'2';

        vector<string> temp;

        for(int j=0 ; j<output.size() ; j++){

            for(int k=0 ; k<5 && table[index][k]!='\0' ; k++){

                temp.push_back(output[j] + table[index][k]); //for merging both buts its o(n^3)

            }

        }

        output = temp;

    }

    return output;
}
};