#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x; // x为指数
    double y; // 系数
    map<int, double, greater<int>> A, B, C, D, E; // 被除数、除数、商、去0余数、去0商
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        A[x] = y;
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        B[x] = y;
    }
    while(A.begin()->first >= B.begin()->first) //当余数的第一项的指数大于除数的第一项的指数时就要继续除
    {
        x = A.begin()->first - B.begin()->first;
        y = A.begin()->second / B.begin()->second;
        C[x] = y; //记录商
        for(auto &e : B)
            A[e.first + x] -= e.second * y; //被除数 - （刚求得的商 * 除数）  =  余数
        A.erase(A.begin()); //最高次项消失
    }
    for(auto &e : A) //余数去0 放入D
        if(abs(e.second) >= 0.05)
            D[e.first] = e.second;
    for(auto &e : C) //商去0 放入E
        if(abs(e.second) >= 0.05)
            E[e.first] = e.second;
    cout << E.size();
    if(E.size())
        for(auto &e : E)
            printf(" %d %.1lf", e.first, e.second);
    else cout << " 0 0.0";
    cout << endl << D.size();
    if(D.size())
        for(auto &e : D)
            printf(" %d %.1lf", e.first, e.second);
    else cout << " 0 0.0";
    system("pause");
}