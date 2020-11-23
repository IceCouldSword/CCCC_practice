#include<bits/stdc++.h>
using namespace std;
class node{ //树节点
    public:
    int data; 
    node *left, *right;
};
void insert(node* &root, int data)  //建树
{
    if(root == NULL)
    {
        root = new node;
        root->left = root->right = NULL;
        root->data = data;
        return;
    }
    else if(data < root->data)
        insert(root->left, data);
    else 
        insert(root->right, data);
}
void preOrder(node* root, vector<int>&vi)  //前序遍历
{
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}
void preOrderM(node* root, vector<int>&vi) //镜像树前序遍历
{
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrderM(root->right, vi);
    preOrderM(root->left, vi);
}
void postOrder(node* root, vector<int>&vi) //后序遍历
{
    if(root == NULL) return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}
void postOrderM(node* root, vector<int>&vi) //镜像树后序遍历
{
    if(root == NULL) return;
    postOrderM(root->right, vi);
    postOrderM(root->left, vi);
    vi.push_back(root->data);
}
vector<int> start,pre,preM,post,postM;
int main()
{
    int n, num;
    cin >> n;
    node* root = new node;
    root = NULL;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        start.push_back(num);
        insert(root, num);
    }
    preOrder(root, pre);
    preOrderM(root, preM);
    if(start == pre)
    {
        cout << "YES" << endl;
        postOrder(root, post);
        for(int i = 0; i < n; i++)
        {
            cout << post[i];
            if(i != n - 1) cout << " ";
        }
    }
    else if(start == preM)
    {
        cout << "YES" << endl;
        postOrderM(root, postM);
        for(int i = 0; i < n; i++)
        {
            cout << postM[i];
            if(i != n - 1) cout << " ";
        }
    }
    else
        cout << "NO";
    system("pause");
}