class Solution{
public:
    int divide(int dividend, int divisor) {
        bool isNeg = false;

        if(dividend < 0 && divisor < 0){
            isNeg = false;
            
            if(divisor == -1){
                if(dividend == -2147483648LL){
                    return 2147483647;
                }
                return -dividend;
            }
        }
        else if(dividend < 0 || divisor < 0){
            isNeg = true;

            if(divisor == 1){
                return dividend;
            }
        }

        unsigned long long div = abs((long long)dividend);
        unsigned long long dio = abs((long long)divisor);

        long long res = 0;

        while(div >= dio){
            div -= dio;
            res++;
        }

        if(isNeg){
            res = -res;

            if(res < -2147483648LL){
                return -2147483648LL;
            }
        }
        else{
            if(res > 2147483647LL){
                return 2147483647;
            }
        }

        return res;
    }
};