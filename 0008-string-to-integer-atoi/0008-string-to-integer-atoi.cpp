class Solution {
public:
int myAtoi(string s) {
bool isNegitive = false , isStarted = false;
int letter = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '-' && letter == 0 && !isStarted) {
            isNegitive = true;
            isStarted = true;
        }

        else if (s[i] == '+' && letter == 0 && !isStarted) {
            isNegitive = false; // handling + cases
            isStarted = true;
        }

        else if (s[i] == ' ' && !isStarted) {
            // ignore leading whitespace
        }

        else if (s[i] < '0' || s[i] > '9') {
            return isNegitive ? -letter : letter;
        }

        if (s[i] - 48 >= 0 && s[i] - 48 <= 9) {

            isStarted = true;

            if (letter < INT_MAX / 10 || (letter == INT_MAX / 10 && (s[i] - 48) <= 7)) { // why 7 as for the last digit its 7 and /10 as *10 may overflow it and error comes

                letter = (s[i] - 48) + (letter * 10);

            } else {

                return isNegitive ? INT_MIN : INT_MAX;

            }

        }

        else if (letter != 0) {

            return isNegitive ? -letter : letter;

        }

    }

    return isNegitive ? -letter : letter;
}
};