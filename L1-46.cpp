#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, num = 1, cnt = 1, flag = 0;
    cin >> x;
    while(1)
    {
        if(num < x && flag == 0)
            num = num * 10 + 1;
        else
        {
            flag = 1;
            cout << num / x;
            if(num % x == 0)    
            {
                cout << " " << cnt;
                break;
            }
            else num = (num % x) * 10 + 1;
        }
        cnt++;
    }
    system("pause");
}