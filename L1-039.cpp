#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[10005] = {' '};
    int n, size = 0, x;
    cin >> n;
    getchar();
    while((s[size] = getchar()) != 10)
        size++;
    if(size % n != 0)
    {
        while(size % n != 0)
            s[size++] = ' ';
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = size / n - 1; j >= 0; j--)
        {
            cout << s[j * n + i];
        }
        cout << endl;
    }
    system("pause");
}