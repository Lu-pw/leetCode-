#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution01
{
public:
    int findContentChildren(vector<int>& g,vector<int>& s)
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child = 0;
        int cookie = 0;
        while(child < g.size() && cookie < s.size())
        {
            if(g[child] <= s[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main()
{
    solution01 s01;
    vector<int> g = {5,10,2,9,15,9};
    vector<int> s = {6,1,20,3,8};
    cout << s01.findContentChildren(g,s);
    return 0;
}
