/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return nullptr;
        }
        ListNode *fst = head;
        ListNode *lst = head;
        ListNode* prev = head;
        while(lst && lst->next){
            prev = fst;
            fst = fst -> next;
            lst = lst -> next -> next;
        }
        prev->next = fst->next;
        delete fst;
        return head;
        
    }
};