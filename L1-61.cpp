#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x, y;
    cin >> x >> y;
    double temp = x / (pow(y, 2));
    printf("%.1lf\n", temp);
    if(temp > 25)
        cout << "PANG";
    else cout << "Hai Xing";
    system("pause");
}