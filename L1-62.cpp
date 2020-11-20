#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum1, sum2;
    cin >> n;
    string s;
    while(n--)
    {  
        sum1 = sum2 = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
        {
            if(i < 3) sum1 += s[i];
            else sum2 += s[i];
        }
        if(sum1 == sum2)
            cout << "You are lucky!" << endl;
        else
            cout << "Wish you good luck." << endl;
    }
    system("pause");
}