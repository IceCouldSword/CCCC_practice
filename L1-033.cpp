#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y, n, num;
    cin >> y >> n;
    for (int i = y; i <= 3000; i++)
    {
        set<int> s;
        num = i;
        for (int j = 0; j < 4; j++)
        {
            s.insert(num % 10); //取每一位数放入s中
            num /= 10;
        }
        if (s.size() == n)
        {
            printf("%d %04d", i - y, i);
            break;
        }
    }
    system("pause");
}