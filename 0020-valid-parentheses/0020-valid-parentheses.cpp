class Solution {
public:
bool isValid(string s) {

vector<char> input;

    int counter =0;

    while(s[counter] != '\0'){

        if(s[counter] == '('  || s[counter] == '{'  || s[counter] == '['){
            input.push_back(s[counter]);
        }
        else if(s[counter] == ')'  || s[counter] == '}'  || s[counter] == ']'){

          if(input.empty()){
            return false; //nothing there so pull of push no sense 
          }

          if(input.back() == '(' && s[counter] == ')'){
              input.pop_back();
          }
          else if(input.back() == '{' && s[counter] == '}'){
              input.pop_back();
          }
          else if(input.back() == '[' && s[counter] == ']'){
              input.pop_back();
          }
          else{
              return false; //not in syallabus 
          }
        }

        counter++;
    }

    if(input.empty()){
        return true;

    }
    else{
        return false;
    }
}
};