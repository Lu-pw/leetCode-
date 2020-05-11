#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
    void generate(string item,int n,vector<string> &result)
    {
        if(item.length() == 2*n)
        {
            result.push_back(item);
            return;
        }
        generate(item + '(',n,result);
        generate(item + ')',n,result);
    }
};


class solution02
{
public:
    void generate(string item,int left,int right,vector<string> &result)
    {
        if(left == 0 && right == 0)
        {
            result.push_back(item);
            return;
        }
        if(left > 0)
        {
            generate(item + '(',left-1,right,result);
        }
        if(left < right)
        {
            generate(item + ')',left,right-1,result);
        }
    }
};
int main()
{
    vector<string> result;
    solution s01;
    s01.generate("",2,result);
    for(int i = 0;i < result.size();i++)
    {
        cout << result[i]<< " ";
    }
    cout << endl;

    result.clear();
    solution02 s02;
    s02.generate("",3,3,result);
    for(int i = 0;i < result.size();i++)
    {
        cout << result[i]<< " ";
    }

}
