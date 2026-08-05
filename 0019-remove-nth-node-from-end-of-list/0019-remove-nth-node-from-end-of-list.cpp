class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* temp = head;

    int length = 0;

    // find length
    while(temp != nullptr){
        length++;
        temp = temp->next;
    }

    // nth from end 
    int position = length - n + 1;

    temp = head;
    ListNode* prev = nullptr;

    int counter = 1;

    while(counter != position){

        prev = temp;
        temp = temp->next;
        counter++;

    }

    // deleting head node 
    if(prev == nullptr){
        head = head->next;
        delete temp;
        return head;
    }
    //else same concept 
    prev->next = temp->next;
    delete temp;

    return head;
}

};