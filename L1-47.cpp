#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    string s;
    cin >> n;
    while(n--)
    {
        cin >> s >> a >> b;
        if((a < 15 || a > 20) || (b < 50 || b > 70))
            cout << s << endl;
    }
    system("pause");
}