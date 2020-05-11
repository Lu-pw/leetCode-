#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> Q;
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
    cout << "Q.back is " << Q.back() << endl;
    cout << "Q.size() is " << Q.size();

}
