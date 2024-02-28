#include<bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int n;
    int *arr;
    
    Heap(int size)
    {
        n = size;
        arr = new int[n + 1];
    }

    void insert(int element)
    {
        n++;
        arr[n] = element;

        int index = n;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapify(int index)
    {
        while (true)
        {
            int child1 = 2 * index;
            int child2 = child1 + 1;

            if (child1 <= n)
            {
                int largerChild = child1;

                if (child2 <= n && arr[child2] > arr[child1])
                {
                    largerChild = child2;
                }

                if (arr[largerChild] > arr[index])
                {
                    swap(arr[index], arr[largerChild]);
                    index = largerChild;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
};
