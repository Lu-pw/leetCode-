#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int>& a,const pair<int,int> &b)
{
    return a.first < b.first;
}

class solution01
{
public:
    int findMinArrowShots(vector<pair<int,int>>& points)
    {
        if(points.size() == 0)
        {
            return 0;
        }
        sort(points.begin(),points.end(),cmp);

        int shoot_num = 1;
        int shoot_begin = points[0].first;
        int shoot_end = points[0].second;

        for(int i = 1;i < points.size();i++)
        {
            if(shoot_begin < points[i].first && points[i].first <= shoot_end)
            {
                shoot_begin = points[i].first;
                if(shoot_end > points[i].second)
                {
                    shoot_end = points[i].second;
                }
            }
            else
            {
                shoot_num++;
                shoot_begin = points[i].first;
                shoot_end = points[i].second;
            }
        }
        return shoot_num;
    }
};

int main()
{
    solution01 s01;
    vector<pair<int,int>> points = {{1,3},{2,4},{4,6},{7,9}};
    cout << s01.findMinArrowShots(points);
}
