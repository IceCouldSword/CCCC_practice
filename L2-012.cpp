#include<bits/stdc++.h>
using namespace std;
int num[1005];
int getIndex(int x) //获取下标
{
    for(int i = 0; i < 1005; i++)
        if(num[i] == x) return i;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        make_heap(num, num + i, greater<int>()); //建堆
    }
    make_heap(num, num + n, greater<int>()); //循环完之后还要再执行一次
    getchar();
    while(m--)
    {
        string s;
        int x, y, xi = 0, yi = 0;
        getline(cin, s);
        if(s.find("root") != s.npos)
        {
            sscanf(s.c_str(), "%d is the root", &x); 
            if(x == num[0]) //判断根
                cout << "T" << endl;
            else
                cout << "F" << endl;
        }
        else if(s.find("siblings") != s.npos)
        {
            sscanf(s.c_str(), "%d and %d are siblings", &x, &y);
            xi = getIndex(x);
            yi = getIndex(y);
            int f = (min(xi, yi) - 1) / 2;
            if((min(xi, yi) == f * 2 + 1) && (max(xi, yi) == f * 2 + 2)) //判断兄弟
                cout << "T" << endl;
            else
                cout << "F" << endl;
        }
        else if(s.find("parent") != s.npos)
        {
            sscanf(s.c_str(), "%d is the parent of %d", &x, &y); 
            xi = getIndex(x);
            yi = getIndex(y);
            if((xi * 2 + 1 == yi) || (xi * 2 + 2 == yi))//判断父子
                cout << "T" << endl;
            else
                cout << "F" << endl;
        }
        else if(s.find("child") != s.npos)
        {
            sscanf(s.c_str(), "%d is a child of %d", &x, &y); 
            xi = getIndex(x);
            yi = getIndex(y);
            if((yi * 2 + 1 == xi) || (yi * 2 + 2) == xi)//判断父子
                cout << "T" << endl;
            else
                cout << "F" << endl;
        }
    }
    system("pause");
}