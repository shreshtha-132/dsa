ListNode* middleNode(ListNode* head) {
        ListNode *fst = head;
        ListNode *lst = head;
        while(lst && lst->next){
            fst = fst -> next;
            lst = lst -> next -> next;
        }
        return fst;
        
    }