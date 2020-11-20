#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x, y;
    cin >> x >> y;
    double temp1 = (100 - x + 100) * y / 2 ;
    double temp2 = (100 - x) * (100 - y) / 2;
    cout << 5000 - temp1 - temp2;
    system("pause");
}