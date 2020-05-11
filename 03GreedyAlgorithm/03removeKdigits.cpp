#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class solution01
{
public:
    string removeKdigits(string &num,int k)
    {
        vector<int> s;
        string result = "";
        for(int i = 0;i < num.length();i++)
        {
            int number = num[i] - '0';
            while(s.size() != 0 && s.back() > number && k > 0)
            {
                k--;
                s.pop_back();
            }
            if(number != 0 || s.size() != 0)
            {
                s.push_back(number);
            }
        }
        while(s.size() != 0 && k > 0)
        {
            s.pop_back();
            k--;
        }
        for(int i = 0; i < s.size();i++)
        {
            result += s[i] + '0';
        }
        if(result == "")
        {
            result = "0";
        }
        return result;
    }
};

int main()
{
    solution01 s01;
    string num = "100200";//200
    int k = 1;
    cout << s01.removeKdigits(num,k);
}
