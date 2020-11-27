#include<bits/stdc++.h>
using namespace std;
int num[1005];
int order[1005];
int n, m, k;
bool judge()
{
    stack<int> s;
    int p1 = 0, p2 = 0, i = 0;
    for(int i = 0; i < n; i++)
    {
        s.push(num[i]);
        while(!s.empty() && order[p2] == s.top())
        {
            p2++;
            s.pop();
        }
        if(s.size() >= m + 1)
            return 0;
    }
    if(!s.empty())
        return 0;
    else
        return 1;
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        order[i] = i + 1;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> num[j];
        }
        if(judge())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
}