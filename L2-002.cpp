#include<bits/stdc++.h>
using namespace std;
class point
{
    public:
        int num;
        int next;
}node[100005];
int vis[100005];
int ans1[100005];
int ans2[100005];
int main()
{
    int add, n, cnt1 = 0, cnt2 = 0;
    memset(vis, 0, sizeof(vis));
    cin >> add >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cin >> node[x].num >> node[x].next;
    }
    for(int i = add; i != -1; i = node[i].next)
    {
        int temp = abs(node[i].num);
        if(vis[temp] == 0)
        {
            vis[temp] = 1;
            ans1[cnt1] = i;
            cnt1++;
        }
        else
        {
            ans2[cnt2] = i;
            cnt2++;
        }
    }
    for(int i = 0; i < cnt1; i++)
    {
        if(i != cnt1 - 1)
            printf("%05d %d %05d\n", ans1[i], node[ans1[i]].num, ans1[i+1]);
        else
            printf("%05d %d -1\n", ans1[i], node[ans1[i]].num);
    }
    for(int i = 0; i < cnt2; i++)
    {
        if(i != cnt2 - 1)
            printf("%05d %d %05d\n", ans2[i], node[ans2[i]].num, ans2[i+1]);
        else
            printf("%05d %d -1\n", ans2[i], node[ans2[i]].num);
    }
    system("pause");
}