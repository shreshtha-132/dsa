// queue using array
//FIFO
//enter element from rear and increment it , to delete use the front
// and decrement the rear.
#include<bits/stdc++.h>
using namespace std;

class stack{
    
    public:
        int n; // size of queue
        int *arr;
        int front,rear; // front and rear of queue
        stack(int size)
        {
            n = size;
            arr = new int[n];
            front = 0;
            rear = 0;
        }
        void queue(int element)
        {
            if(rear<n)
            {
                arr[rear] = element;
                rear++;
            }
            else
            {
                cout << "queue is full" << endl;
            }
        }
        void dequeue()
        {
            if(rear<=0)
            {
                cout << "queue is empty" << endl;
            }
            else
            {
                arr[front]=0;
                for(int i=front;i<rear;i++)
                {
                    arr[i] = arr[i+1];
                }
                rear--;
            }
            
        }
        
    
};
