#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class solution
{
public:
    vector<string> findRepeatedDnaSquences(string s)
    {
        map<string,int> word_map;
        vector<string> result;
        for(int i = 0;i < s.length();i++)
        {
            string word = s.substr(i,10);
            if(word_map.find(word) != word_map.end())
            {
                word_map[word] += 1;
            }
            else
            {
                word_map[word] = 1;
            }
        }
        map<string,int> ::iterator it;
        for(it = word_map.begin();it != word_map.end();it++)
        {
            if(it->second > 1)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};

class solution02
{
public:
    int g_hash_map[1048576] = {0};
    string change_int_to_DNA(int DNA)
    {
        static const char DNA_CHAR[] = {'A','C','G','T'};
        string str;
        for(int i = 0;i < 10;i++)
        {
            //将一个长度为10的片段，从整数转为字符串
            str += DNA_CHAR[DNA & 3];//取出最低位
            DNA = DNA >> 2;//去除最低位
        }
        return str;
    }
    vector<string> findRepeatedDnaSquences(string s)
    {
        vector<string> result;
        if(s.length() < 10)
        {
            return result;
        }
        for(int i = 0;i < 1048576;i++)
        {
            //每次调用时需要更新全局数组
            g_hash_map[i] = 0;
        }
        int char_map[128] = {0};
        char_map['A']  = 0;//设置字符到整数的转换数组
        char_map['C'] = 1;
        char_map['G'] = 2;
        char_map['T'] = 3;
        int key = 0;
        //将DNA字符串的前10个字符
        for(int i = 9;i >= 0;i--)
        {//以四进制进行存储
            key = (key << 2)+ char_map[s[i]];
        }
        g_hash_map[key] = 1;
        for(int i = 10;i < s.length();i++)
        {//干掉最高两位
            key = key>>2;
            //最高为变为新来的字母
            key = key|char_map[(s[i]<<18)];
            g_hash_map[key]++;
        }for(int i = 0;i < 1048576;i++)
        {
            if(g_hash_map[i] > 1)
            {
                result.push_back(change_int_to_DNA(i));
            }//将出现次数大于2的片段push进入结果
        }
    }
};

int main()
{
    string s = "aaaaacccccbbbaaaaacccccttt";
    solution s01;
    vector<string> ret = s01.findRepeatedDnaSquences(s);
    for(int i = 0;i < ret.size();i++)
    {
        cout << ret[i] << "  ";
    }
    cout << endl;
    solution s02;
    ret = s02.findRepeatedDnaSquences(s);
    for(int i = 0;i < ret.size();i++)
    {
        cout << ret[i] << "  ";
    }
}
