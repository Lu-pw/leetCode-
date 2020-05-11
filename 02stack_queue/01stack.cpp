#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    if(s.empty())
    {
        cout << "s is empty!" <<endl;
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
