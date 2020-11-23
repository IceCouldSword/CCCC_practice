#include<bits/stdc++.h> //并查集
using namespace std;
class node
{
    public:
    int id;
    int cnt;
    int s;
}no[10005];  //每条记录
class family
{
    public:
    int id;
    int num;
    int cnt;
    int s;
    double avgs;
    double avgcnt;
}fam[10005]; //家庭信息
int fa[10005];
bool operator < (family &a, family &b) //比较函数
{
    if(a.avgs == b.avgs)
        return a.id < b.id;
    return a.avgs > b.avgs;
}
int find(int x)
{
    if(fa[x] == x)
        return x;
    else 
        return fa[x] = find(fa[x]);
}
int vis[10005]; //记录每个访问过的编号
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x < y)
        fa[y] = fa[x];
    else
        fa[x] = fa[y];
}
void init()
{
    for(int i = 0; i < 10005; i++)
    {
        fa[i] = i;
        fam[i].id = 0;
        fam[i].cnt = 0;
        fam[i].num = 0;
        fam[i].s = 0;
        fam[i].avgs = 0;
        fam[i].avgcnt = 0;
        vis[i] = 0;
    }
}
int main()
{
    int n;
    cin >> n;
    init();
    int id, f, m, k, kid;
    for(int i = 0; i < n; i++)
    {
        cin >> id >> f >> m >> k;
        vis[id] = 1;
        if(f != -1)
        {
            unite(id, f);
            vis[f] = 1;
        }
        if(m != -1)
        {
            unite(id, m);
            vis[m] = 1;
        }
        for(int j = 0; j < k; j++)
        {
            cin >> kid;
            unite(id, kid);
            vis[kid] = 1;
        }
        no[i].id = id;
        cin >> no[i].cnt >> no[i].s;
    }
    for(int i = 0; i < n; i++)
    {
        int id = no[i].id;
        id = find(id);
        fam[id].s += no[i].s;
        fam[id].cnt += no[i].cnt;
    }
    for(int i = 0; i < 10005; i++)
    {
        if(vis[i])
        {
            fa[i] = find(i);
            //if(fam[fa[i]].num != 0)
            fam[fa[i]].id = fa[i];
            fam[fa[i]].num++;
            fam[fa[i]].avgs = fam[fa[i]].s * 1.0 / fam[fa[i]].num;
            fam[fa[i]].avgcnt = fam[fa[i]].cnt * 1.0 / fam[fa[i]].num;
        }
    }
    sort(fam,fam+10005);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(fam[i].num != 0) ans++;
        else break;
    }
    cout << ans << endl;
    for(int i = 0; i < ans; i++)
        printf("%04d %d %.3f %.3f\n", fam[i].id, fam[i].num, fam[i].avgcnt, fam[i].avgs);
    system("pause");
}