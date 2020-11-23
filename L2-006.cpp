#include<bits/stdc++.h>
using namespace std;
class point
{
    public:
    int data;
    point *left;
    point *right;
};
point* createTree(int *in, int *post, int num) //根据中序和后序建立二叉树
{
    if(num == 0) return NULL;
    int i = 0;
    int ch = post[num - 1]; //记录后序遍历中最后一个，作为根节点
    while(i < num && in[i] != ch) i++; //在中序中找到这个数据
    int left = i;
    int right = num - i - 1; //将中序分为两部分，分别递归
    point *node = new point;
    node->data = ch;
    node->left = createTree(in, post, left);
    node->right = createTree(in + left + 1, post + left, right);
    return node;
}
void levelOrder(point *root, queue<point*>&que)
{
    int first = 0;
    que.push(root);
    while(!que.empty())
    {
        if(first == 0)
        {
            cout << que.front()->data;
            first = 1;
        }
        else
            cout << " " << que.front()->data;
        if(que.front()->left != NULL)
            que.push(que.front()->left);
        if(que.front()->right != NULL)
            que.push(que.front()->right);
        que.pop();
    }
}
int post[50]; //后序 
int in[50]; //中序
queue<point*> que; //层序遍历队列
int main()
{
    int n;
    cin >> n;
    point *root = new point;
    for(int i = 0; i < n; i++)
        cin >> post[i];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    root = createTree(in, post, n);
    levelOrder(root, que);
    system("pause");
}