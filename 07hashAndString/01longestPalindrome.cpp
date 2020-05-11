#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution
{
public:
    int longestPalidrome(string s)
    {
        int char_map[128] = {0};//�ַ���ϣ
        int max_length = 0;//���Ĵ�ż��������󳤶�
        int flag = 0;//�Ƿ������ĵ�
        for(int i = 0;i < s.length();i++)
        {
            char_map[s[i]]++;//���������±�ͳ���ַ���
        }
        for(int i = 0;i < 128;i++)
        {
            if(char_map[i]%2 == 0)
            {
                max_length += char_map[i];
            }
            else
            {
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag;
    }
};

int main()
{
    string str = "abccccdabed";
    solution s01;
    cout <<s01.longestPalidrome(str);
}