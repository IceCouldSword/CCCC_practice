#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int citymap[550][550]; //矩阵
int num[550]; //每个城市消防员的数量
int dis[550]; //最短距离数组
int vis[550]; //记录是否访问过该城市
int sum[550]; //召集消防员总数
int pre[550]; //前驱节点
int cnt[550]; //同长路径长度
int n,m, s, d;
void dijkstra() //s为出发点，d为目标点
{
    memset(dis, INF, sizeof(dis)); //初始化
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    dis[s] = 0;
    sum[s] = num[s];
    cnt[s] = 1;
    while(1)
    {
        int pos = -1;
        for(int i = 0; i < n; i++) //找dis中最小的作为当前位置
            if(vis[i] != 1 && (pos == -1 || dis[i] < dis[pos]))
                pos = i;
        if(pos == -1)
            break;
        vis[pos] = 1; //记录走过的
        for(int i = 0; i < n; i++)
        {
            if(citymap[pos][i] == INF) continue; //如果不通直接continue
            if(vis[i] != 1 && (dis[pos] + citymap[pos][i] < dis[i])) //如果找到了比当前路径小的就更新
            {
                dis[i] = dis[pos] + citymap[pos][i];
                pre[i] = pos;
                sum[i] = sum[pos] + num[i];
                cnt[i] = cnt[pos];
            }
            else if(dis[pos] + citymap[pos][i] == dis[i]) //如果路径相等则更新cnt
            {
                cnt[i] += cnt[pos];
                if(num[i] + sum[pos] > sum[i]) //如果新救援数量大于目前的数量 则更新sum
                {
                    sum[i] = sum[pos] + num[i];
                    pre[i] = pos;
                }
            }
        }
    }
    cout << cnt[d] << " " << sum[d] << endl;
    int k = d;
    vector<int> path;
    while(k != s)
    {
        path.push_back(k);
        k = pre[k];
    }
    path.push_back(k);
    reverse(path.begin(),path.end());
    for(int i = 0; i < path.size(); i++)
    {
        if(i != 0)
            cout << " ";
        cout << path[i];
    }
    cout  << endl;
}
int main()
{
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++)  //初始化
        for(int j = 0; j < n; j++)
            citymap[i][j] = INF;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    for(int i = 0; i < m; i++) //输入数据
    {
        int x, y;
        cin >> x >> y;
        cin >> citymap[x][y];
        citymap[y][x] = citymap[x][y];
    }
    dijkstra();
    system("pause");
}