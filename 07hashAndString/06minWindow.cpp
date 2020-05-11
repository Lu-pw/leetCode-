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
            return false;//���s���ָ��ַ�����С��t�г����ַ�����
        }
    }
    return true;
}

class solution
{
public:
    string minWindow(string s,string t)
    {
        const int MAX_ARRAY_LEN = 128;//char0-127�����������±��¼�ַ�����
        int map_t[MAX_ARRAY_LEN] = {0};//��¼t�ַ������ַ�����
        int map_s[MAX_ARRAY_LEN] = {0};//��¼s�ַ������ַ�����
        vector<int> vec_t;//��¼t�ַ�������Щ�ַ�
        for(int i = 0; i < t.length(); i++)
        {
            map_t[t[i]]++;//��¼t�ַ�������
        }
        for(int i = 0; i < MAX_ARRAY_LEN; i++)
        {
            if(map_t[i] > 0)
            {
                vec_t.push_back(i);//��t���ַ�������vec_t
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
                    //���ͷָ��ָ����ַ�û����T�г���
                    begin++;
                }
                //ͷָ��ָ����ַ�������T�У������г���T�и��ַ��������ַ�
                else if(map_s[begin_ch] > map_t[begin_ch])
                {
                    map_s[begin_ch]--;
                    begin++;//����ͷָ������
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
                }//�滻��������Ӧ���ַ���
            }
        }
        return result;
    }
};


int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    const int MAX_ARRAY_LEN = 128;//char0-127�����������±��¼�ַ�����
    int map_t[MAX_ARRAY_LEN] = {0};//��¼t�ַ������ַ�����
    int map_s[MAX_ARRAY_LEN] = {0};//��¼s�ַ������ַ�����
    vector<int> vec_t;//��¼t�ַ�������Щ�ַ�
    for(int i = 0; i < s.length(); i++)
    {
        map_s[s[i]]++;//��¼s�ַ�������
    }
    for(int i = 0; i < t.length(); i++)
    {
        map_t[t[i]]++;//��¼t�ַ�������
    }
    for(int i = 0; i < MAX_ARRAY_LEN; i++)
    {
        if(map_t[i] > 0)
        {
            vec_t.push_back(i);//��t���ַ�������vec_t
        }
    }

    solution s01;
    cout << s01.minWindow(s,t);
}
