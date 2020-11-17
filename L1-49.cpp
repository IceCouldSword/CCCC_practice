#include<bits/stdc++.h>
using namespace std;
int main()
{
    int pos[105][11][11]; // 第i个学校第j个队第k个队员
    int num[105];//每个学校队伍
    int n, maxnum = 0, pre = -1, x = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        maxnum = max(maxnum, num[i]);
    }
    for(int j = 0; j < maxnum; j++)
    {
        for(int k = 0; k < 10; k++) // 每个队员
        {
            for(int i = 0; i < n; i++)
            {
                if(num[i] > j)
                {
                    if(pre == i) //如果上一个学校和这个学校是同一个
                        x += 2;
                    else 
                        x++;
                    pos[i][j][k] = x;
                    pre = i;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << "#" << i + 1 << endl;
        for(int j = 0; j < num[i]; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                if(k!=9)
                    cout << pos[i][j][k] << " ";
                else cout << pos[i][j][k] << endl;
            }
        }
    }
    system("pause");
}