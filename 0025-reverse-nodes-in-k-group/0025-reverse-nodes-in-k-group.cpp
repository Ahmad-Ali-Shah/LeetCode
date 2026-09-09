
/*
VVVV IIIMPORTANT

HERE
FIRST FOUND OUT COUNTER>0 ERROR ELSE NOT 

THEN WE WILL TALK ABOUT PREVIOUS AND NEXT POINTERS 

AND THEN PREV HOLD THE SORTED ARRAY WHILE OTHER HOLD THE NON SORTED BY SORT I MEAN REVERESED

PREV =1 AND OTHER NEXT BE 2,3,4 
NOW 
WE NEED TO BREAK AND LINK BREAK AND LINK THAT'S IT 

*
*/













class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;

        int counter = 0;

        while (counter < k && start) {
            counter++;
            start = start->next;
        }

        if (counter < k) {
            return head;
        }

        counter = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (counter < k) {
          
            ListNode* preserver = curr->next;
            curr->next = prev;

           
            prev = curr;
            curr = preserver;

            counter++;
        }

        
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};