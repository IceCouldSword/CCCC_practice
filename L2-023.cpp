#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int Map[505][505];
int a[505];
set<int> color;
int main()
{
    int v, e, k, num1, num2;
    cin >> v >> e >> k;
    memset(Map, inf, sizeof(Map));
    for(int i = 0; i < e; i++)
    {
        cin >> num1 >> num2;
        Map[num1][num2] = Map[num2][num1] = 1;
    }
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        color.clear();
        int flag = 0;
        memset(a, 0, sizeof(a));
        for(int j = 1; j <= v; j++)
        {
            cin >> temp;
            color.insert(temp);
            a[j] = temp;
        }
        if(color.size() != k)
        {
            cout << "No" << endl;
            continue;
        }
        for(int j = 1; j <= v; j++)
            for(int z = 1; z <= v; z++)
                if(Map[j][z] != inf && a[j] == a[z])
                {
                    flag = 1;
                    break;
                }
        if(flag == 1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    system("pause");
}