#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, flag = 0;
    char ch, temp;
    cin >> ch >> n;
    getchar();
    char arr[105][105];
    char res[105][105];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%c", &arr[i][j]);
            if(arr[i][j] != ' ') temp = arr[i][j];
        }
        getchar();
    }
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(arr[i][j] != ' ')
                res[n-i-1][n-j-1] = ch;
            else 
                res[n-i-1][n-j-1] = ' ';
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(res[i][j] == ch && arr[i][j] != temp)
            {
                flag = 1;
                break;
            }
    if(flag == 0)
    cout << "bu yong dao le" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
    system("pause");
}