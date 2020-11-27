#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    int next;
    int pre;
}Node[100005];
int main()
{
    int start, n, add, num = 0;
    cin >> start >> n;
    int pre = start, post = n;
    for(int i = 0; i < n;i++)
    {
        cin >> add;
        cin >> Node[add].data >> Node[add].next;
    }
    for(int i = start; i != -1;)
    {
        int temp = i;
        if(Node[i].next == -1)
            post = i;
        i = Node[i].next;
        Node[i].pre = temp;
        num++;  //坑点  测试点3会给出不存在于链表的结点，故需要统计链表中节点个数
    }
    if(num % 2 == 0)
    {
        for(int i = 0; i < num / 2; i++)
        {
            printf("%05d %d %05d\n", post, Node[post].data, pre);
            post = Node[post].pre;
            if(i == num / 2 - 1)
                printf("%05d %d -1\n", pre, Node[pre].data);
            else
                printf("%05d %d %05d\n", pre, Node[pre].data, post);
            pre = Node[pre].next;
        }
    }
    else
    {
        for(int i = 0; i < num / 2; i++)
        {
            printf("%05d %d %05d\n", post, Node[post].data, pre);
            post = Node[post].pre;
            printf("%05d %d %05d\n", pre, Node[pre].data, post);
            pre = Node[pre].next;
        }
        printf("%05d %d -1\n", pre, Node[pre].data);
    }
    system("pause");
}