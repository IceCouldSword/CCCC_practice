#include<bits/stdc++.h>
using namespace std;
vector<double> vec[10005];
vector<double> ans;
int main()
{
    int n, k ,m;
    double sum = 0, avg, num;
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < k; j++)
        {
            cin >> num;
            vec[i].push_back(num);
        }
        sort(vec[i].begin(),vec[i].end());
        for(int j = 1; j < vec[i].size() - 1; j++)
            sum += vec[i][j];
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end(), less<int>());
    for(int i = n - m; i < n; i++)
    {
        if(i != n - m) 
            printf(" %.3lf", ans[i] * 1.0 / (k - 2));
        else
            printf("%.3lf", ans[i] * 1.0 / (k - 2));
    }
    system("pause");
}