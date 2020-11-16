#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        double h,w;
        cin >> h >> w;
        double temp = (h - 100) * 0.9 * 2;
        if(abs(w - temp) < temp * 0.1)
            cout << "You are wan mei!" << endl;
        else if((w - temp) >= temp * 0.1 && w > temp)
            cout << "You are tai pang le!" << endl;
        else
            cout << "You are tai shou le!" << endl;
    }
    system("pause");
}