ListNode* Tail = nullptr;
class Solution {

    void insertAtTail(ListNode*& head, int value) {

        ListNode* temp = new ListNode(value, nullptr);

        if(head == nullptr){

            head = temp;

            Tail = head;

        }

        else{

        Tail->next = temp;
        Tail = temp;
    }
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;
        ListNode* newHead = nullptr;
       

        while(temp) {


            ListNode* nextOnes = temp->next;

            // skip repeated values
            while(nextOnes && nextOnes->val == temp->val) {
                nextOnes = nextOnes->next;
            }


           
              
              if(temp)
             insertAtTail(newHead, temp->val);

             temp= nextOnes;
        }

        return newHead;
    }
}; 