#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_window_ok(int map_s[],int map_t[], vector<int> &vec_t)
{
    for(int i = 0; i < vec_t.size(); i++)
    {
        if(map_s[vec_t[i]] < map_t[vec_t[i]])
        {
            return false;//如果s出现该字符数量小于t中出现字符数量
        }
    }
    return true;
}

class solution
{
public:
    string minWindow(string s,string t)
    {
        const int MAX_ARRAY_LEN = 128;//char0-127，利用数组下标记录字符个数
        int map_t[MAX_ARRAY_LEN] = {0};//记录t字符串各字符个数
        int map_s[MAX_ARRAY_LEN] = {0};//记录s字符串各字符个数
        vector<int> vec_t;//记录t字符串有哪些字符
        for(int i = 0; i < t.length(); i++)
        {
            map_t[t[i]]++;//记录t字符串个数
        }
        for(int i = 0; i < MAX_ARRAY_LEN; i++)
        {
            if(map_t[i] > 0)
            {
                vec_t.push_back(i);//将t中字符串存入vec_t
            }
        }
        int begin = 0;
        string result;
        for(int i = 0;i < s.length();i++)
        {
            map_s[s[i]]++;
            while(begin < i)
            {
                char begin_ch = s[begin];
                if(map_t[begin_ch] == 0)
                {
                    //如果头指针指向的字符没有在T中出现
                    begin++;
                }
                //头指针指向的字符出现在T中，窗口有超过T中该字符个数的字符
                else if(map_s[begin_ch] > map_t[begin_ch])
                {
                    map_s[begin_ch]--;
                    begin++;//窗口头指针右移
                }
                else
                {
                    break;
                }
            }
            if(is_window_ok(map_s,map_t,vec_t))
            {
                int new_window_len = i - begin +1;
                if(result == "" || new_window_len < result.length())
                {
                    result = s.substr(begin,new_window_len);
                }//替换窗口所对应的字符串
            }
        }
        return result;
    }
};


int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    const int MAX_ARRAY_LEN = 128;//char0-127，利用数组下标记录字符个数
    int map_t[MAX_ARRAY_LEN] = {0};//记录t字符串各字符个数
    int map_s[MAX_ARRAY_LEN] = {0};//记录s字符串各字符个数
    vector<int> vec_t;//记录t字符串有哪些字符
    for(int i = 0; i < s.length(); i++)
    {
        map_s[s[i]]++;//记录s字符串个数
    }
    for(int i = 0; i < t.length(); i++)
    {
        map_t[t[i]]++;//记录t字符串个数
    }
    for(int i = 0; i < MAX_ARRAY_LEN; i++)
    {
        if(map_t[i] > 0)
        {
            vec_t.push_back(i);//将t中字符串存入vec_t
        }
    }

    solution s01;
    cout << s01.minWindow(s,t);
}
