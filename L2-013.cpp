#include<bits/stdc++.h> //DFS
using namespace std;
int vis[505]; //访问过的城市
int Map[505][505]; //地图
int n, m, k;
void DFS(int x)
{
    vis[x] = 1;
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0 && Map[x][i] == 1)
            DFS(i);
    }
}
int getcnt() //求图的连通分量
{
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            DFS(i);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> m;
    int num1, num2;
    memset(Map, 0, sizeof(Map));
    for(int i = 0; i < m; i++)
    {
        cin >> num1 >> num2;
        Map[num1][num2] = Map[num2][num1] = 1;
    }
    int cnt = getcnt();
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> num1;
        for(int j = 0; j < n; j++)
        {
            Map[num1][j] = Map[j][num1] = 0;
        }
        int temp = getcnt();
        if(temp > cnt + 1)
            cout << "Red Alert: City " << num1 << " is lost!" << endl;
        else
            cout << "City " << num1 << " is lost." << endl;
        if(i == n - 1)
            cout << "Game Over." << endl;
        cnt = temp;
    }
    system("pause");
}