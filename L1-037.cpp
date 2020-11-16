#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    if(b == 0)
        cout << a << "/" << b << "=" << "Error";
    else if(b < 0)
        printf("%.0lf/(%.0lf)=%.2lf", a, b, a / b);
    else 
        printf("%.0lf/%0.lf=%.2lf", a, b, a / b);
    system("pause");
}