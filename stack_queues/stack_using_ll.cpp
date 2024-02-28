//stack usign ll
//lifo

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int element)
        {
            data = element;
            next = nullptr;
        }
};

class LinkedList
{
    public:
        Node* head;
        LinkedList(int data)
        {
            Node* temp = new Node(data);
            head = temp;
        }
        void push(int data)
        {
            Node* temp = new Node(data);
            Node* curr = head;
            while(curr->next!=nullptr)
            {
                curr = curr->next;
            }
            curr->next = temp;
            
            
        }
        void pop()
        {
            if (head == nullptr)
            {
                cout << "Stack is empty. Cannot pop." << endl;
                return;
            }
        
            Node* curr = head;
            Node* prev = nullptr;
        
            while (curr->next != nullptr)
            {
                prev = curr;
                curr = curr->next;
            }
        
            if (prev != nullptr)
            {
                prev->next = nullptr;
                delete curr;
            }
            else
            {
                // If there is only one node in the list
                delete head;
                head = nullptr;
            }
        }

        void top()
        {
            Node* curr = head;
            while(curr->next!=nullptr)
            {
                curr = curr->next;
            }
            cout << curr->data << endl;
        }
};