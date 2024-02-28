#include<bits/stdc++.h>

void insertb(std::stack<int> &stack, int x) {
    if (stack.empty()) {
        stack.push(x);
    } else {
        int top = stack.top();
        stack.pop();
        insertb(stack, x);
        stack.push(top);
    }
}

void help(std::stack<int> &stack) {
    if (!stack.empty()) {
        int top = stack.top();
        stack.pop();
        help(stack);
        insertb(stack, top);
    }
}

void reverseStack(std::stack<int> &stack) {
    help(stack);
    // The stack is now reversed after the help function is executed.
}


#include <bits/stdc++.h> 

void insertSort(stack<int> &stack,int element)
{
	if(stack.empty())
	{
		stack.push(element);
	}
	else if(stack.top()<element)
	{
		stack.push(element);
	}
	else
	{
		int top = stack.top();
		stack.pop();
		insertSort(stack,element);
		stack.push(top);
	}
}
void help(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}
	else
	{
		int top = stack.top();
		stack.pop();
		help(stack);
		insertSort(stack, top);
	}
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	help(stack);
}