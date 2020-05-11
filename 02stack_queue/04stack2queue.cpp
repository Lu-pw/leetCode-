#include <stack>
#include <iostream>

using namespace std;

class Queue
{
public:
    Queue() {};
    void push(int x)
    {
        stack<int> temp_s;
        while(!_data.empty())
        {
            temp_s.push(_data.top());
            _data.pop();
        }
        temp_s.push(x);
        while(!temp_s.empty())
        {
            _data.push(temp_s.top());
            temp_s.pop();
        }
        data_size++;
    }
    int pop()
    {
        int x = _data.top();
        _data.pop();
        data_size--;
        return x;
    }
    int front()
    {
        return _data.top();
    }
    int size()
    {
        return data_size;
    }
    bool empty()
    {
        return _data.empty();
    }

private:
    stack<int> _data;
    int data_size = 0;
};

int main()
{
    Queue Q;
    if(Q.empty())
    {
        cout << "Q is empty!"<<endl;
    }
    Q.push(5);
    Q.push(6);
    Q.push(10);
    cout << "Q.front is " <<Q.front() << endl;
    Q.pop();
    cout << "Q.front is " <<Q.front() << endl;
    Q.push(1);
//    cout << "Q.back is " << Q.back() << endl;
    cout << "Q.size() is " << Q.size();

}
