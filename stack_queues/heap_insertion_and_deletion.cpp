#include<bits/stdc++.h>
using namespace std;
class Heap
{
    public:
        int n;
        int *arr;
        int pointer=0; //always points to last element added in the heap
        Heap(int size)
        {
            n = size;
            arr = new int[n+1];
        }
        void insert(int element)
        {
            pointer++;
            
            if(pointer<=n)
            {
                arr[pointer]=element;
                int index = pointer;
                
                
                while(index>1)
                {
                    int parent = index/2;
                    if(arr[parent]<arr[index])
                    {
                        int temp = arr[index];
                        arr[index] = arr[parent];
                        arr[parent] = temp;
                        index = parent;
                    }
                    else
                    {
                        return;
                    }
                }
            }
            else
            {
                cout << "heap is full" << endl;
            }
        }
        
        void delete() 
        {
                // this function deletes the root element of the heap and 
                // exchanges the root node with the last node and then 
                // follows the top to bottom approach to settle the node
                // to its correct point.
                
                if(pointer<=1)
                {
                    cout << "heap is empty" << endl;
                }
                else
                {
                    arr[1]=arr[pointer];
                    pointer--;
                    
                    int index =1;
                    while(index<pointer)
                    {
                        // also add a check condition here to check if the child1 and child2's index which is generated
                        // is correct index or not.
                        int child1 = 2*index;
                        int child2 = child1+1;
                        if(arr[index]>arr[child1] && arr[index]>arr[child2] )
                        {
                            // this means it follows max heap so no changes to be done.
                        }
                        else
                        {
                            // find the largest of children and swap with parent.
                            if(arr[child1]>arr[child2])
                            {
                                int temp = arr[child1];
                                arr[child1]=arr[index];
                                arr[index]=temp;
                                index = child1;
                            }
                            else
                            {
                                int temp = arr[child2];
                                arr[child2]=arr[index];
                                arr[index]=temp;
                                index = child2;
                            }
                        }
                    }
                }
        }
        
        void print()
        {
            for(int i=1;i<=n;i++)
            {
                cout << arr[i] << endl;
            }
        }
        
};