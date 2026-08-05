class Solution {
public:
bool isPalindrome(int x) {

    if(x < 0){
        return 0;
    }

    int temp = x, rev = 0;

    while(temp != 0){

        double digit = temp % 10;
        temp /= 10;

        if(rev <= INT_MAX/10 ){ 
            rev = digit + rev * 10;
        }

    }

    if(x == rev){
        return true;
    }
    else{
        return false;
    }
}

};