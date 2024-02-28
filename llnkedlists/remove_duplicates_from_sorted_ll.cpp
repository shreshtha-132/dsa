/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    else
    {
        Node* temp = head->next;
        while(temp!=nullptr)
        {
            Node* prev = temp->prev;
            Node* next = temp->next;
            if(prev->data == temp->data)
            {
                prev->next = next;
                if (next != nullptr)
                {
                    next->prev = prev;
                }
                delete temp;
                temp = next;
            }
            else{
                temp = temp->next;
            }
        }
    }
    return head;
}
