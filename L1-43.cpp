#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, id, hour, minute, cnt, sum;
    char ch;
    int book[1005] = {0}, time[1005] = {0};
    bool flag = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cnt = sum = flag = 0;
        while(1)
        {
            scanf("%d %c %d:%d", &id, &ch, &hour, &minute);
            if(id == 0) break;
            if(ch == 'S')
            {
                book[id] = 1;
                time[id] = hour * 60 + minute;
            }
            else if(ch == 'E' && book[id] == 1)
            {
                book[id] = 0;
                cnt++;
                sum += hour * 60 + minute - time[id];
                flag = 1;
            }
        }
        if(flag == 0) cout << "0 0" << endl;
        else cout << cnt << " " << int(sum * 1.0 / cnt + 0.5) << endl;
    }
    system("pause");
}