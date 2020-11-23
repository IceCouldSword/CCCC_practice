#include<bits/stdc++.h>
using namespace std;
int fa[105];
int arr[105][105] = {0};
int find(int x)
{
    if(fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    else
        fa[x] = y;
}
int main()
{
    for(int i = 0; i < 105; i++)
        fa[i] = i;
    int n, m, k, x, y, z;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        if(z == 1) 
            unite(x, y);
        else
            arr[x][y] = arr[y][x] = 1;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        if(arr[x][y] != 1) //不是敌人
        {
            x = find(x);
            y = find(y);
            if(x == y)
                cout << "No problem" << endl;
            else
                cout << "OK" << endl;
        }
        else
        {
            x = find(x);
            y = find(y);
            if(x == y)
                cout << "OK but..." << endl;
            else
                cout << "No way" << endl;
        }
    }
    system("pause");
}