#include <iostream>
#include <string>
using namespace std;

int int_func(int key,int table_len)
{
    return key%table_len;
}

int string_func(string key,int table_len)
{
    int sum = 0;
    for(int i = 0;i < key.length();i++)
    {
        sum += key[i];//不同的整数或字符串，
        //由于哈希函数的选择，被映射到了同一个下标处，产生了冲突
    }
    return sum % table_len;
}

int main()
{
    const int TABLE_LEN = 10;
    int hash_map[TABLE_LEN] = {0};
    hash_map[int_func(99999995,TABLE_LEN)]++;
    hash_map[int_func(5,TABLE_LEN)]++;
    hash_map[string_func("abc",TABLE_LEN)]++;
    hash_map[string_func("bac",TABLE_LEN)]++;
    for(int i = 0;i < TABLE_LEN;i++)
    {
        printf("%d ",i);
        cout <<  hash_map[i] << endl;
    }
}
