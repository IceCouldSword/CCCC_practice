#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k, i = 0;
    cin >> k;
    string s;
    while(1)
    {
        i++;
        cin >> s;
        if(s == "End") break;
        if(i % (k + 1) != 0)
        {
            if(s == "ChuiZi") cout << "Bu" << endl;
            else if(s == "JianDao") cout << "ChuiZi" << endl;
            else if(s == "Bu") cout << "JianDao" << endl;
        }
        else
        {
            if(s == "ChuiZi") cout << "ChuiZi" << endl;
            else if(s == "JianDao") cout << "JianDao" << endl;
            else if(s == "Bu") cout << "Bu" << endl;
        }
    }
    system("pause");
}