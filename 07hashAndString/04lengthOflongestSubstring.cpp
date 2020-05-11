#include <string>
#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
    int lengthOflongestSubstring(string s)
    {
        int begin = 0;//窗口的头指针
        int result = 0;
        string word = "";
        int char_map[128] = {0};
        for(int i = 0;i < s.length();i++)
        {
            char_map[s[i]]++;
            if(char_map[s[i]] == 1)//word中没出现该字符
            {
                word += s[i];
                if(result < word.length())
                {
                    result = word.length();
                }
            }
            else//将重复的s[i]删去
            {
                while(begin < i && char_map[s[i]] > 1)
                {
                    char_map[s[begin]]--;
                    begin++;
                }
                word = "";//更新word
                for(int j = begin;j <= i;j++)
                {
                    word += s[j];
                }
            }
        }
        return result;
    }
};


int main()
{
    string s = "abcdben";
    solution s01;
    cout << s01.lengthOflongestSubstring(s);
}
