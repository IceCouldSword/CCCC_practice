#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int ans = 1;
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = s.size() - 1; j > i; j--)
        {
            int pre = i, post = j;
            while(pre <= post)
            {
                if(s[pre] != s[post]) break;
                pre++;
                post--;
            }
            if(pre > post)
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    system("pause");
}