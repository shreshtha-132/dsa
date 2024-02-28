/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
#include<bits/stdc++.h>
Node *removeLoop(Node *head)
{
    // Write your code here.
    Node* temp = head;
    map<Node*,bool>m;
    while(temp!=nullptr)
    {
        m[temp]=true;
        if(m[temp->next]==true)
        {
            temp->next = nullptr;
            break;
        }
        temp=temp->next;
    }
    return head;
}





/* can also be solved using floyd's algo, run fast and slow pointer, until they point to the same node, or the fast is null,when fast is
null that means no cycle and when if they meet, that means there is a cycle.*/