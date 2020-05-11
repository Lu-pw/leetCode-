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
        map<string,char> word_map;//���ʵ�pattern�ַ���ӳ��
        char used[128] = {0};//�ѱ�ӳ���pattern�ַ�
        string word;//��ʱ�����ֳ��ĵ���
        int pos = 0;//��ǰָ���pattern�ַ�
        str.push_back(' ');//�Կո�ֵ��ʣ��������⴦�����һ��
        for(int i = 0;i < str.length();i++)
        {
            if(str[i] == ' ')//�����ո񣬻���µ���
            {
                if(pos == pattern.length())//pattern�ַ�����
                {
                    return false;
                }
                if(word_map.find(word) == word_map.end())
                {//δ�ҵ�word���ҵ���pattern�ַ�
                    if(used[pattern[pos]] == 1)
                    {
                        return false;
                    }
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;
                }
                else
                {//�ҵ���word����pattern����Ӧ
                    if(word_map[word] != pattern[pos])
                    {
                        return false;
                    }
                }
                word = "";//��ɵ��ʣ����word
                pos++;//pattern�ַ���һ��
            }
            else
            {
                word += str[i];
            }
        }
        if(pos != pattern.length())//��pattern��word
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
