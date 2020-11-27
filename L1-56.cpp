#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string name[10005];
    int num[10005];
    int avg = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> name[i] >> num[i];
        avg += num[i];
    }
    avg = avg / n / 2;
    int min, temp = 105;
    for(int i = 0; i < n; i++)
    {
        if(abs(num[i] - avg) < temp)
        {
            temp = abs(num[i] - avg);
            min = i;
        }
    }
    cout << avg << " " << name[min] ;
    system("pause");
}