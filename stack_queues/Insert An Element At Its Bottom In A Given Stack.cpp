#include <bits/stdc++.h> 

void help(stack<int>& myStack, int x)
{
    
    if(myStack.empty())
    {
        myStack.push(x);
        
    }
    else
    {
        int top  = myStack.top();
        myStack.pop();
        help(myStack,x);
        myStack.push(top);

    }

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    help(myStack,x);
    return myStack;
}
