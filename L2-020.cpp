#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node
{
    public:
    double data; //功力值
    vector<int> child;
    bool flag = 0;
}Tree[100005];
double sum = 0; //功力总值
double z, r;
void levelOrder() //层序遍历
{
    queue<int> que;
    que.push(0);
    if(Tree[0].flag == 1)   
        sum += z * Tree[0].data;
    while(!que.empty())
    {
        int temp = que.front();
        for(int i = 0; i < Tree[temp].child.size(); i++)
        {
            int child = Tree[temp].child[i];
            if(Tree[child].flag == 1)
                sum += Tree[temp].data * Tree[child].data * r;
            else
                Tree[child].data = Tree[temp].data * r;
            que.push(child);
        }
        que.pop();
    }
}
int main()
{
    int n, m, num;
    cin >> n >> z >> r;
    r = (100 - r) * 1.0 / 100;
    Tree[0].data = z;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        if(m == 0)
        {
            Tree[i].flag = 1; //得道弟子
            cin >> num;
            Tree[i].data = num;
        }
        for(int j = 0; j < m; j++)
        {
            cin >> num;
            Tree[i].child.push_back(num);
        }
    }
    levelOrder();
    sum = (ll)sum;
    printf("%.0lf", sum);
    system("pause");
}