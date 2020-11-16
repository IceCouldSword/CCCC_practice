#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char ch;
    double num, res;
    cin >> n;
    while(n--)
    {
        cin >> ch >> num;
        if(ch == 'M')
            res = num / 1.09;
        else
            res = num * 1.09;
        printf("%.2lf\n", res);
    }
    system("pause");
}