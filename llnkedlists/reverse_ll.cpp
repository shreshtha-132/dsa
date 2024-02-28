#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int n)
        {
            data = n;
            next = nullptr;
        }
};

class LinkedList
{
    public:
        Node* head;

        LinkedList()
        {
            head = nullptr;
        }

        void traverse()
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

        void add(int n)
        {
            Node* temp = new Node(n);
            if (head == nullptr)
            {
                head = temp;
            }
            else
            {
                Node* t = head;
                while(t->next != nullptr)
                {
                    t = t->next;
                }
                t->next = temp;
            }
        }
        
        void reverse()
        {
            if(head==nullptr|| head->next == nullptr)
            {
                return;
            }
            else
            {
                
                Node *prev;
                prev = nullptr;
                
                while(head!=nullptr)
                {
                    Node* temp = head->next;
                    head->next = prev;
                    prev = head;
                    head = temp;
                }
                head = prev;
            }
        }
};
int main()
{
    LinkedList myList;

    // Adding elements to the linked list
    myList.add(1);
    myList.add(2);
    myList.add(3);
    myList.add(4);

    cout << "Original List:" << endl;
    myList.traverse();

    // Reversing the linked list
    myList.reverse();

    cout << "\nReversed List:" << endl;
    myList.traverse();

    return 0;
}

