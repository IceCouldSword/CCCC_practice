#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int deep;
    vector<int> child;
}Node[100005];
int root ;
int maxdeep = 1;
void levelOrder()
{
    queue<node> que;
    que.push(Node[root]);
    while(!que.empty())
    {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < temp.child.size(); i++)
        {
            Node[temp.child[i]].deep = temp.deep + 1;
            maxdeep = max(maxdeep, Node[temp.child[i]].deep);
            que.push(Node[temp.child[i]]);
        }
    }
}
int main()
{
    int n, num;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num;
        if(num == -1)
            root = i; //记录老祖宗
        else
            Node[num].child.push_back(i);
    }
    Node[root].deep = 1;
    levelOrder();
    cout << maxdeep << endl;
    int ans[100005];
    int j = 0;
    for(int i = 1; i <= n; i++)
    {
        if(Node[i].deep == maxdeep)
        {
            ans[j] = i;
            j++;
        }
    }
    sort(ans, ans + j);
    for(int i = 0; i < j; i++)
    {
        if(i != 0)  cout << " ";
        cout << ans[i];
    }
    system("pause");
}