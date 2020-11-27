#include<bits/stdc++.h>
using namespace std;
int isPrime(int x)
{
    if(x < 2) return 1;
    else
    {
        for(int i = 2; i <= sqrt(x); i++)
        {
            if(x % i == 0) return 1;
        }
    }
    return 2;
}
int vis[100005];
int main()
{
    int left, right, num, sum;
    bool flag = 0;
    memset(vis, 0, sizeof(vis));
    cin >> left >> right;
    map<int, int> m;
    for(int i = left; i <= right; i++)
    {
        sum = 0;
        num = i;
        vector<int> vec;
        while(num != 1)
        {
            sum = 0;
            while(num)
            {
                sum += (num % 10) * (num % 10);
                num /= 10;
            }
            num = sum;
            if(find(vec.begin(), vec.end(), num) != vec.end())
                break;
            vec.push_back(num);
            vis[num] = 1;
        }
        if(num == 1)
            m[i] = vec.size();
    }
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(vis[it->first] == 0)
        {
            cout << it->first << " " << it->second * isPrime(it->first) << endl;
            flag = 1;
        }
    }
    if(flag == 0)
        cout << "SAD" << endl;
    system("pause");
}