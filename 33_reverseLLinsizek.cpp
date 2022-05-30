int lengthLL(ListNode* head){
    int count = 0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

//By Using Recursion, take care of only first k size Nodes then call a function for remaining.

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL && head->next == NULL){
        return head;
    }
    if(lengthLL(head)<k)    return head;
    
    ListNode* prev = NULL; 
    ListNode* next = NULL;
    ListNode* curr = head;
    int count = 0;
    
    while(curr!=NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(curr!=NULL){
        head->next = reverseKGroup(curr,k);
    }
    return prev;
}