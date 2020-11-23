#include<bits/stdc++.h>
using namespace std;
set<int> ans[55];
int main()
{
    int n, m, k, num, num1, num2;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            cin >> num;
            ans[i].insert(num);
        }
    }
    cin >> k;
    int cnt; //相同数字的数量
    for(int i = 0; i < k; i++)
    {
        cin >> num1 >> num2;
        num1--;
        num2--;
        auto it = ans[num2].begin();
        cnt = 0;
        for(int j = 0; it != ans[num2].end(); j++, it++)
        {
            if(ans[num1].find(*it) != ans[num1].end())
                cnt++;
        }
        double res = cnt * 1.0 / (ans[num1].size() + ans[num2].size() - cnt);
        printf("%.2lf%%\n", res * 100);
    }
    system("pause");
}