#include<bits/stdc++.h>
using namespace std;
int res[1005] = {0};
int main()
{
    int n, k, num, maxindex, temp = 0;
    cin >> n;
    while(n--)
    {
        cin >> k;
        while(k--)
        {
            cin >> num;
            res[num] ++;
        }
    }
    for(int i = 0; i < 1005; i++)
    {
        if(res[i] > temp)
        {
            temp = res[i];
            maxindex = i;
        }
        else if(res[i] == temp && i > maxindex)
        {
            temp = res[i];
            maxindex = i;
        }
    }
    cout << maxindex << " " << temp;
    system("pause");
}