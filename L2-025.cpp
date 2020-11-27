#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
vector<int> Map[10005];
int main()
{
    int n, m, num1, num2;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> num1 >> num2;
        Map[num1].push_back(num2);
    }
    int k, np, num;
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        map<int, int> Map2;
        cin >> np;
        int flag = 0;
        for(int j = 1; j <= np; j++)
        {
            cin >> num;
            Map2[num] = 1;
        }
        for(int j = 1; j <= n; j++)
        {
            if(Map2[j] == 0)
            {
                for(int l = 0; l < Map[j].size(); l++)
                {
                    if(Map2[Map[j][l]] == 0)
                    {
                        flag = 1;
                            break;
                    }
                }
                if(flag)
                    break;
            }
        }
        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    system("pause");
}