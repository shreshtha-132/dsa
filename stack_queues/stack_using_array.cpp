// stack using array

#include<bits/stdc++.h>
using namespace std;

class stack{
    
    public:
        int n; // size of stack
        int *arr;
        int sp; // stack pointer
        stack(int size)
        {
            n = size;
            arr = new int[n];
            sp = 0;
        }
        void push(int element)
        {
            if(sp<n)
            {
                arr[sp]=element;
                sp++;
            }
            else
            {
                cout << "stack is full" << endl;
            }
        }
        void pop()
        {
            if(sp==0)
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                sp--;
                arr[sp]=0;
            }
            
        }
        void print()
        {
            for(int i=0;i<=sp;i++)
            {
                cout << arr[i] << endl;
            }
        }
        
    
};
