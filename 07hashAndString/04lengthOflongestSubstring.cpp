#include <string>
#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
    int lengthOflongestSubstring(string s)
    {
        int begin = 0;//���ڵ�ͷָ��
        int result = 0;
        string word = "";
        int char_map[128] = {0};
        for(int i = 0;i < s.length();i++)
        {
            char_map[s[i]]++;
            if(char_map[s[i]] == 1)//word��û���ָ��ַ�
            {
                word += s[i];
                if(result < word.length())
                {
                    result = word.length();
                }
            }
            else//���ظ���s[i]ɾȥ
            {
                while(begin < i && char_map[s[i]] > 1)
                {
                    char_map[s[begin]]--;
                    begin++;
                }
                word = "";//����word
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
