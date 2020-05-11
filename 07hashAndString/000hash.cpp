#include <iostream>
#include <string>
using namespace std;

int main()
{
    int char_map[128] = {0};
    string str = "abcdefggghekaaa";
    for(int i = 0;i < str.length();i++)
    {
        char_map[str[i]]++;
    }
    for(int i = 0;i < 128;i++)
    {
        if(char_map[i] > 0)
        {
            cout << i <<":"<< char_map[i] << " ";
        }
    }
    return 0;
}
