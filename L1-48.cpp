#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1, b1, a2, b2, num, first = 0;
    cin >> a1 >> b1;
    int **mat1 = new int*[a1];
    for(int i = 0; i < a1; i++)
        mat1[i] = new int[b1];
    for(int i = 0; i < a1; i++)
        for(int j = 0; j < b1; j++)
            cin >> mat1[i][j];
    cin >> a2 >> b2;
    int **mat2 = new int*[a2];
    for(int i = 0; i < a2; i++)
        mat2[i] = new int[b2];
    for(int i = 0; i < a2; i++)
        for(int j = 0; j < b2; j++)
            cin >> mat2[i][j];
    if(b1 != a2)
        cout << "Error: " << b1 << " != " << a2;
    else
    {
        cout << a1 << " " << b2 << endl;
        for(int i = 0; i < a1; i++)
        {
            for(int j = 0; j < b2; j++)
            {
                num = 0;
                for(int k = 0; k < b1; k++)
                    num += mat1[i][k] * mat2[k][j];
                if(first == 0)
                {
                    cout << num;
                    first = 1;
                }
                else
                    cout << " " << num;
            }
            cout << endl;
            first = 0;
        }
    }
    system("pause");
}