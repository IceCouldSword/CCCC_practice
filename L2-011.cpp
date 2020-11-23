#include<bits/stdc++.h>
using namespace std;
class point
{
    public:
    int data;
    point *left;
    point *right;
};
point *createTree(int *in, int *pre, int num)
{
    if(num == 0) return NULL;
    int left = 0, right = num - 1, i = 0;
    point *root = new point;
    int temp = pre[0];
    while(temp != in[i] && i < num) i++;
    left = i;
    right = num - i - 1;
    root->data = temp;
    root->left = createTree(in, pre + 1, left);
    root->right = createTree(in + i + 1, pre + i + 1, right);
    return root;
}
void levelOrder(point *root)
{
    queue<point*> que;
    int first = 0;
    if(root == NULL) return;
    que.push(root);
    while(!que.empty())
    {
        if(que.front()->left != NULL)
            que.push(que.front()->left);
        if(que.front()->right != NULL)
            que.push(que.front()->right);
        if(first == 0)
        {
            cout << que.front()->data;
            first = 1;
        }
        else
            cout << " " << que.front()->data;
        que.pop();
    }
}
void MirrorTree(point *&root)
{
    if(root == NULL) return;
    point *temp = new point;
    MirrorTree(root->left);
    MirrorTree(root->right);
    temp = root->left;
    root->left = root -> right;
    root->right = temp;
}
int pre[100];
int in[100];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> pre[i];
    point *root = new point;
    root = createTree(in, pre, n);
    MirrorTree(root);
    levelOrder(root);
    system("pause");
}