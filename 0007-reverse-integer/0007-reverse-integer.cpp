class Solution {
public:
    int reverse(int x) {

        int counter = 0;

        while (x != 0) {
           
          //////////////////////////////

          //FOR MAX MIN 


          /////////////////////////////

           if (counter > INT_MAX / 10 || (counter == INT_MAX / 10 && x % 10 > 7)) //since we are talking about last digit of x so 
                return 0;

            if (counter < INT_MIN / 10 || (counter == INT_MIN / 10 && x % 10 < -8))
                return 0;


         ////////////////////////////

         
            counter = (x % 10) + (counter * 10);


            x /= 10;
        }

        return counter;
    }
};