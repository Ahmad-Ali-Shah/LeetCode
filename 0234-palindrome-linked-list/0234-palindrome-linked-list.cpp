/*

class Solution {

    ListNode* getLast(int counter, ListNode* head) {
        int count = 0;

        while (count < counter && head) {
            head = head->next;
            count++;
        }

        return head;
    }

public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) {
            return true;
        }

        ListNode* start = head;
        ListNode* end = head;

        int counter = 0;

        while (end->next != nullptr) {
            end = end->next;
            counter++;
        }

        /////////////////////////

        /// yarrr arry ma travese kiiun ni kr sakta

        /////////////////////////

        int index = 0;

        while (index <= counter / 2) {

            if (start->val != end->val) {
                return false;
            }

            end = getLast(counter - index - 1, head);

            start = start->next;
            index++;
        }

        return true;
    }
};

high complexity o(n^2)
*/

//////////////////////////

// took from other

///////////////////


/*

goated algortham btw 

find middle 

break array in two 

then after that from 


mid reverse each one 

then after reversing linked list 

compart both 


*/

class Solution {
public:
ListNode* reverse(ListNode* head){

    ListNode* prev = NULL;

    while(head != NULL){
        ListNode* next = head -> next;
        head-> next = prev;

        prev =head;
        head = next;
    }

    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){

           

            slow = slow -> next;
            fast = fast -> next->next;
        }

        slow = reverse(slow);

        fast =head;
        
        while(slow != NULL){
        if(slow -> val != fast -> val)
         return false;
        slow = slow -> next;
        fast = fast -> next;
        }
        return true;
    }
};