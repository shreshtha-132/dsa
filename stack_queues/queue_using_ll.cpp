//queue usign ll
//lifo
//maintain two pointers, front and rear, use front to add element and rear to delete.
// when adding thorugh front, make a new node and append the previous existing ll to the next pointer of 
// new node, and declare the new node as head.

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
        Node* tail;
        LinkedList(int data)
        {
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        }
        void queue(int data)
        {
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            
            
        }
        void dequeue()
        {
            
        }

        void top()
        {
            
        }
};