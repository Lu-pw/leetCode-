#include <iostream>
#include <stack>

using namespace std;

class Stack
{
public:
    Stack(){min_stack.push(1000);};
    void push(int x)
    {
        _data.push(x);
        if(x <= min_stack.top())
        {
            min_stack.push(x);
        }
        else
        {
            x = min_stack.top();
            min_stack.push(x);
        }
    }
    int pop()
    {
        min_stack.pop();
        _data.pop();
    }
    int top()
    {
        return _data.top();
    }
    int getMin()
    {
        return min_stack.top();
    }
private:
    stack<int> _data;
    stack<int> min_stack;

};

int main()
{
    Stack s;
    s.push(5);
    s.push(-6);
    s.push(10);
    cout << s.top() << endl;
    cout << "Hello world!" << endl;
    cout << s.getMin() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    return 0;
}
