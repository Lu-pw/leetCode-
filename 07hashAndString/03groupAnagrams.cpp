#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

class solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> str_vec)
    {
        map<string,vector<string>> anagram;
        vector<vector<string>> result;
        for(int i = 0;i < str_vec.size();i++)
        {
            string str = str_vec[i];
            sort(str.begin(),str.end());
            if(anagram.find(str) == anagram.end())
            {
                vector<string> item;
                anagram[str] = item;
            }
                anagram[str].push_back(str_vec[i]);
        }
        map<string,vector<string>>::iterator it;
        for(it = anagram.begin();it != anagram.end();it++)
        {
            result.push_back((*it).second);
        }
        return result;
    }
};

class solution02
{
public:
    void change_to_vector(string &str,vector<int> &vec)
    {
        for(int i = 0;i < 26;i++)
        {
            vec.push_back(0);
        }
        for(int i = 0;i < str.length();i++)
        {
            vec[str[i] - 'a']++;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string> str_vec)
    {
        map<vector<int>,vector<string>> anagram;
        vector<vector<string>> result;
        for(int i = 0;i < str_vec.size();i++)
        {
            vector<int> vec;
            change_to_vector(str_vec[i],vec);
            if(anagram.find(vec) == anagram.end())
            {
                vector<string> item;
                anagram[vec] = item;
            }
            anagram[vec].push_back(str_vec[i]);
        }
        map<vector<int>,vector<string>> ::iterator it;
        for(it = anagram.begin();it != anagram.end();it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};

int main()
{
    vector<string> str_vec = {"eat","tea","tan","ate","nat","bat"};
    solution s01;
    vector<vector<string>> ret = s01.groupAnagrams(str_vec);
    for(int i = 0;i < ret.size();i++)
    {
        for(int j = 0; j < ret[i].size();j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    solution02 s02;
    ret = s02.groupAnagrams(str_vec);
    for(int i = 0;i < ret.size();i++)
    {
        for(int j = 0; j < ret[i].size();j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
};

