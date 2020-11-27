#include<bits/stdc++.h>
using namespace std;
int n, k, num;
class node
{
    public:
    int deep;
    vector<int> next;
}Node[100005];
int vis[100005];
int levelOrder(int root)
{
    int ans;
    queue<int> que;
    que.push(root);
    while(!que.empty())
    {
        int temp = que.front();
        que.pop();
        ans = temp;
        for(int i = 0; i < Node[temp].next.size(); i++)
            que.push(Node[temp].next[i]);
    }
    //ans = Node[ans].next[0];
    return ans;
}
int main()
{
    cin >> n;
    int ans;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            cin >> num;
            Node[i].next.push_back(num);
            vis[num] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
            ans = levelOrder(i);
    }
    cout << ans << endl;
    system("pause");
}