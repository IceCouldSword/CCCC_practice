#include<bits/stdc++.h>
using namespace std;
class person
{
    public:
    int id;
    char sex; //M男F女 A无记录
    int f;
    int m;
}per[100005];
int vis[100005];
int flag; //是否在五代之内
void DFS(int x, int num) //五代之内的亲戚全部标记
{
    if(num > 4) return;
    if(vis[x] == 0)
    {
        vis[x] = 1;
        if(per[x].f != -1)
            DFS(per[x].f, num+1);
        if(per[x].m != -1)
            DFS(per[x].m, num+1);
    }
    else
    {
        flag = 1;
        return;
    }
}
void init()
{
    for(int i = 0; i < 100005; i++)
    {
        per[i].id = i;
        per[i].sex = 'A';
        per[i].f = -1;
        per[i].m = -1;
    }
}
int main()
{
    int n, f, m, id;
    char sex;
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id >> sex >> f >> m;
        per[id].id = id;
        per[id].sex = sex;
        per[id].f = f;
        per[id].m = m;
        if(f != -1)
        {
            per[f].id = f;
            per[f].sex = 'M';
        }
        if(m != -1)
        {
            per[m].id = m;
            per[m].sex = 'F';
        }
    }
    int k, num1, num2;
    cin >> k;
    while(k--)
    {
        flag = 0;
        memset(vis, 0, sizeof(vis));
        cin >> num1 >> num2;
        if(per[num1].sex == per[num2].sex)
            cout << "Never Mind" << endl;
        else
        {
            DFS(num1, 0);
            DFS(num2, 0);
            if(flag)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    system("pause");
}