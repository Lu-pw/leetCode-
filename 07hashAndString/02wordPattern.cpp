#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class solution
{
public:
    bool wordPattern(string pattern,string str)
    {
        map<string,char> word_map;//单词到pattern字符的映射
        char used[128] = {0};//已被映射的pattern字符
        string word;//临时保存拆分出的单词
        int pos = 0;//当前指向的pattern字符
        str.push_back(' ');//以空格分单词，无需特殊处理最后一个
        for(int i = 0;i < str.length();i++)
        {
            if(str[i] == ' ')//遇到空格，获得新单词
            {
                if(pos == pattern.length())//pattern字符用完
                {
                    return false;
                }
                if(word_map.find(word) == word_map.end())
                {//未找到word但找到了pattern字符
                    if(used[pattern[pos]] == 1)
                    {
                        return false;
                    }
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;
                }
                else
                {//找到了word但与pattern不对应
                    if(word_map[word] != pattern[pos])
                    {
                        return false;
                    }
                }
                word = "";//完成单词，清空word
                pos++;//pattern字符后一个
            }
            else
            {
                word += str[i];
            }
        }
        if(pos != pattern.length())//有pattern无word
        {
            return false;
        }
        return true;
    }
};

int main()
{
    string pattern = "abba";
    string str = "dog is is dog";
    solution s01;
    cout << boolalpha << s01.wordPattern(pattern,str);
}
