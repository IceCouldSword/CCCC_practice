#include<bits/stdc++.h> //并查集
using namespace std;
int fa[10005];
int find(int x)
{
    if(x == fa[x]) 
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
void init()
{
    for(int i = 0; i < 10005; i++)
    {
        fa[i] = i;
    }
}
set<int> per;
int num[10005];
int vis[10005];
int main()
{
    int n, k;
    cin >> n;
    init();
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        memset(num, 0, sizeof(num));
        for(int j = 0; j < k; j++)
        {
            cin >> num[j];
            if(per.find(num[j]) != per.end())
                continue;
            else
                per.insert(num[j]);
        }
        for(int j = 0; j < k; j++)
        {
            if(j != k - 1)
                unite(num[j], num[j+1]);
        }
    }
    cout << per.size() << " ";
    int cnt = 0;
    for(auto &e : per)
    {
        int temp = find(e);
        if(vis[temp] == 0)
        {
            cnt++;
            vis[temp] = 1;
        }
    }
    cout << cnt << endl;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        temp1 = find(temp1);
        temp2 = find(temp2);
        if(temp1 == temp2)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    system("pause");
}