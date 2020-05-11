#include <iostream>

using namespace std;

int main()
{
    const int MAX_N = 5;
    int Graph[MAX_N][MAX_N] = {0};
    Graph[0][2] = 1;
    Graph[0][4] = 1;
    Graph[1][0] = 1;
    Graph[1][2] = 1;
    Graph[2][3] = 1;
    Graph[3][4] = 1;
    Graph[4][3] = 1;

    cout << "Graph:" << endl;
    for(int i = 0;i < MAX_N;i++)
    {
        for(int j = 0; j < MAX_N;j++)
        {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}
