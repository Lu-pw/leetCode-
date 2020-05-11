#include <queue>
#include <iostream>

using namespace std;

class Stack
{
public:
    Stack(){};
    void push(int x)
    {
        queue<int> temp_q;
        temp_q.push(x);
        while(!_data.empty())
        {
            temp_q.push(_data.front());
            _data.pop();
        }
        while(!temp_q.empty())
        {
            _data.push(temp_q.front());
            temp_q.pop();
        }
        data_size++;
    }
    int pop()
    {
        int x = _data.front();
        _data.pop();
        data_size--;
        return x;
    }
    int top()
    {
        return _data.front();
    }
    bool empty()
    {
        return _data.empty();
    }
    int size()
    {
        return data_size;
    }
private:
    queue<int> _data;
    int data_size = 0;
};

int main()
{
    Stack s;
    if(s.empty())
    {
        cout << "s is empty!" << endl;
    }
    s.push(5);
    s.push(6);
    s.push(10);
    cout << s.top() << endl;
    cout << "Hello world!" << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    return 0;
}
