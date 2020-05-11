#include <iostream>
#include <map>
#include <string>

using namespace std;
struct ListNode
{
    string key;
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

int main()
{
    map<string,int> hash_map;
    string str1 = "abc";
    string str2 = "aaa";
    string str3 = "xxxxx";
    hash_map[str1] = 1;
    hash_map[str2] = 2;
    hash_map[str3] = 100;
    if(hash_map.find(str1) != hash_map.end())
    {
        cout << str1 << ":" <<hash_map[str1];
    }
    map<string,int>::iterator it;
    for(it = hash_map.begin();it != hash_map.end();it++)
    {
        cout << it->first << ":" <<it->second <<endl;
    }
}
