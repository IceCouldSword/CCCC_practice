#include<bits/stdc++.h>
using namespace std;

void replace(string &a, char b)
{
    while(a.find(b) != a.npos)
    {
        a.replace(a.find(b), 1, "");
    }
}
int main()
{
    string a, b;
    getline(cin, a);
    //getchar();
    getline(cin, b);
    for(int i = 0; i < b.size(); i++)
    {
        replace(a, b[i]);
    }
    cout << a;
    system("pause");
}