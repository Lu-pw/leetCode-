#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution
{
public:
    int longestPalidrome(string s)
    {
        int char_map[128] = {0};//字符哈希
        int max_length = 0;//回文串偶数部分最大长度
        int flag = 0;//是否有中心点
        for(int i = 0;i < s.length();i++)
        {
            char_map[s[i]]++;//利用整数下标统计字符数
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
