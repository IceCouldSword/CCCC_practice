#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l, n;
    char res[100];
    cin >> l >> n;
    int pos = pow(26, l) - n;
    for(int i = l - 1, j = 0; i >= 0; i--, j++)
    {
        int temp = pow(26, i);
        res[j] = pos / temp + 'a';
        pos = pos % temp;
    }
    for(int i = 0; i < l; i++)
        cout << res[i];
    system("pause");
}