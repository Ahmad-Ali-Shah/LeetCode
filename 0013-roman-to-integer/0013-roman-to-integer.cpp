class Solution {
public:
    int romanToInt(string s) {
/*



| Current | Next          | Add Value | Meaning |
| ------- | ------------- | --------: | ------- |
| I       | V             |        +4 | IV      |
| I       | X             |        +9 | IX      |
| X       | L             |       +40 | XL      |
| X       | C             |       +90 | XC      |
| C       | D             |      +400 | CD      |
| C       | M             |      +900 | CM      |
| I       | anything else |        +1 | I       |
| V       | anything else |        +5 | V       |
| X       | anything else |       +10 | X       |
| L       | anything else |       +50 | L       |
| C       | anything else |      +100 | C       |
| D       | anything else |      +500 | D       |
| M       | anything else |     +1000 | M       |


*/
int value = 0;

for(int i = 0; i < s.size(); i++){

    if(i+1 < s.size()){

        if(s[i]=='I' && s[i+1]=='V'){
            value += 4;
            i++;
        }
        else if(s[i]=='I' && s[i+1]=='X'){
            value += 9;
            i++;
        }
        else if(s[i]=='X' && s[i+1]=='L'){
            value += 40;
            i++;
        }
        else if(s[i]=='X' && s[i+1]=='C'){
            value += 90;
            i++;
        }
        else if(s[i]=='C' && s[i+1]=='D'){
            value += 400;
            i++;
        }
        else if(s[i]=='C' && s[i+1]=='M'){
            value += 900;
            i++;
        }
        else if(s[i]=='I'){
            value += 1;
        }
        else if(s[i]=='V'){
            value += 5;
        }
        else if(s[i]=='X'){
            value += 10;
        }
        else if(s[i]=='L'){
            value += 50;
        }
        else if(s[i]=='C'){
            value += 100;
        }
        else if(s[i]=='D'){
            value += 500;
        }
        else if(s[i]=='M'){
            value += 1000;
        }

    }

    else{

        if(s[i]=='I')
         value += 1;
        else if(s[i]=='V')
         value += 5;
        else if(s[i]=='X') 
        value += 10;
        else if(s[i]=='L') 
        value += 50;
        else if(s[i]=='C')
         value += 100;
        else if(s[i]=='D')
         value += 500;
        else if(s[i]=='M')
         value += 1000;

    }

}

return value;

}
};